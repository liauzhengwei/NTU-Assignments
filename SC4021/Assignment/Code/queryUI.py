import pysolr
import streamlit as st
import time
from autocorrect import Speller
from googletrans import Translator
import re
import requests
from wordcloud import WordCloud
import plotly.graph_objects as go
import pysolr
import json
import nltk
from nltk.corpus import stopwords
from nltk.corpus import wordnet
import datetime
import pandas as pd
import plotly.graph_objects as go
# create a connection to a solr server
#@st.cache(allow_output_mutation=True)

def get_daily_hits_breakdown(solr, q="*:*", facet_field="Description", whitelist=None):
    dates = get_dates_with_count(solr, q)
    daily_hits = {date: {} for date in dates}
    for date in dates:
        for item in whitelist:
            query = f"Posted:[{date} TO {date}] AND {facet_field}:{item} AND ({q})"
            daily_hits[date][item] = get_hits(solr, query)
    return daily_hits

def get_dates_with_count(solr, q="*:*"):
    params = {
        "q": q,
        "rows": 0,
        "facet": "True",
        "facet.field": "Posted",
        "facet.mincount": 1,
    }
    results = solr.search(**params)
    date_ranges = results.facets.get("facet_fields", {"Posted": {}})["Posted"]
    dates = [date_ranges[i] for i in range(0, len(date_ranges), 2)]
    return dates

def get_hits(solr, q="*:*"):
    params = {"q": q, "rows": 0}
    results = solr.search(**params)
    return results.hits

def plot_stacked_bar_chart(
    daily_facets,
    whitelist,
    title="Daily Document Count by Term",
    xaxis_title="Date",
    yaxis_title="Count",
):
    """
    Generates a stacked bar chart from a dictionary of dictionaries, where each bar represents a day and the segments of the bar are stacked according to the items in the whitelist.

    :param daily_facets: Dictionary of dictionaries with day as keys and another dictionary with item counts as values.
    :param whitelist: List of items to include in the stacks.
    :param title: Title of the chart.
    :param xaxis_title: Title of the X-axis.
    :param yaxis_title: Title of the Y-axis.
    """
    # Initialize a Plotly figure
    fig = go.Figure()

    # Add a bar to the figure for each item in the whitelist
    for item in whitelist:
        counts = [
            daily_facets[date].get(item, 0) for date in daily_facets
        ]  # Extract counts for each day
        fig.add_trace(go.Bar(name=item, x=list(daily_facets.keys()), y=counts))

    # Update the layout for a stacked bar chart
    fig.update_layout(
        barmode="stack",
        title=title,
        xaxis_title=xaxis_title,
        yaxis_title=yaxis_title,
        xaxis={
            "categoryorder": "category ascending"
        },  # Ensure dates are in ascending order
    )

    return fig

def get_facets(
    solr,
    whitelist_query=None,
    whitelist=None,
    facet_field="Description",
    max_rows=100,
    filter=None,
):
    if whitelist_query is None and whitelist is None:
        whitelist_query = "*:*"
    elif whitelist is not None:
        query = " OR ".join(f"Description:'{word.lower()}'" for word in whitelist)
        if whitelist_query is None:
            whitelist_query = query
        else:
            whitelist_query += f" AND ({query})"

    params = {
        "q": whitelist_query,
        "rows": max_rows,
        "facet": "True",
        "facet.field": facet_field,  # Replace with your text field name
        "facet.limit": -1,  # Return all facets
        "facet.mincount": 1,
    }
    results = solr.search(**params)
    facet_counts = results.facets.get("facet_fields", {facet_field: []})[facet_field]
    word_frequencies = {
        facet_counts[i]: facet_counts[i + 1] for i in range(0, len(facet_counts), 2)
    }
    for key in SYNONYMS.keys():
        if key in word_frequencies:
            if SYNONYMS[key] in word_frequencies:
                word_frequencies[SYNONYMS[key]] += word_frequencies.pop(key)
            else:
                word_frequencies[SYNONYMS[key]] = word_frequencies.pop(key)

    if filter == "stopwords":
        word_frequencies = {
            key: value
            for key, value in word_frequencies.items()
            if key not in stop_words
        }
    elif filter == "whitelist":
        whitelist = [word.lower() for word in whitelist]
        word_frequencies = {
            key: value for key, value in word_frequencies.items() if key in whitelist
        }
    return word_frequencies, results.docs

def create_wordcloud(word_frequencies):
    wordcloud = WordCloud(
        width=1600, height=800, background_color="white", scale=2
    ).generate_from_frequencies(word_frequencies)
    fig = go.Figure(go.Image(z=wordcloud.to_array()))
    fig.update_layout(
        title="Word Cloud", xaxis=dict(visible=False), yaxis=dict(visible=False)
    )
    return fig

def create_wf_pie_chart(word_frequencies, whitelist):
    word_frequencies = {word: freq for word, freq in word_frequencies.items() if word in whitelist}
    fig = go.Figure(
        data=[
            go.Pie(
                labels=[word.title() for word in word_frequencies.keys()],
                values=list(word_frequencies.values()),
            )
        ]
    )
    fig.update_layout(
        title_text="Frequency of Words",
        annotations=[dict(text="", x=0.5, y=0.5, font_size=20, showarrow=False)],
    )
    return fig


def create_wf_bar_chart(word_frequencies):
    fig = go.Figure(
        data=[
            go.Bar(x=list(word_frequencies.keys()), y=list(word_frequencies.values()))
        ]
    )
    fig.update_layout(
        title_text="Frequency of Words", xaxis_title="Words", yaxis_title="Frequency"
    )
    return fig

def create_sentiment_grouped_stacked(solr, q="*:*", facet_field="Description", whitelist_field="Description", whitelist_grouped=None, whitelist_stacked=None):
    dates = get_dates_with_count(solr, q)
    daily_hits = {date: {} for date in dates}
    for date in dates:
        for item in whitelist_grouped:
            daily_hits[date][item] = {}
            for senti in whitelist_stacked:
                query = f"Posted:[{date} TO {date}] AND {whitelist_field}:{item} AND {facet_field}:{senti} AND ({q}) "
                daily_hits[date][item][senti] = get_hits(solr, query)
    return daily_hits

def plot_stock_sentiment(data):
    df_list = []
    for date, stocks in data.items():
        for stock, sentiment in stocks.items():
            df_list.append([date, stock, sentiment['POSITIVE'], sentiment['NEGATIVE'], sentiment['NEUTRAL']])  # Include 'NEUTRAL' sentiment

    df = pd.DataFrame(df_list, columns=['Date', 'Stock', 'Positive', 'Negative', 'Neutral'])  # Include 'Neutral' column
    df_pivot = df.pivot(index='Date', columns='Stock')

    colors = ['#ff0000', '#ff6666', '#ffcccc',  # Red
            '#ff7f0e', '#ffb366', '#ffe0cc',  # Orange
            '#008000', '#66cc66', '#c2f0c2',  # Green
            '#0000ff', '#6699ff', '#cce0ff',  # Blue
            '#800080', '#b366b3', '#cc99cc']  # Purple

    fig = go.Figure()
    bar_width = 0.35
    positions = list(range(len(df_pivot)))
    df_pivot.index = pd.to_datetime(df_pivot.index)
    
    for i, stock in enumerate(df_pivot['Positive'].columns):
        positive_color = colors[i*3]
        negative_color = colors[i*3+1]
        neutral_color = colors[i*3+2]
        
        # Add traces for 'Positive', 'Negative', and 'Neutral' sentiments
        fig.add_trace(go.Bar(x=df_pivot.index, y=df_pivot['Positive'][stock], name=f'Positive {stock}', marker_color=positive_color))
        fig.add_trace(go.Bar(x=df_pivot.index, y=df_pivot['Negative'][stock], name=f'Negative {stock}', marker_color=negative_color))
        fig.add_trace(go.Bar(x=df_pivot.index, y=df_pivot['Neutral'][stock], name=f'Neutral {stock}', marker_color=neutral_color))

    fig.update_layout(
        title='Stock Sentiment Analysis by Date',
        xaxis=dict(
            title='Date',
        ),
        yaxis=dict(title='Number of Articles'),
        barmode='stack'
    )

    return fig

def preload(solr):
    
    whitelist = [
            "Apple",
            "Microsoft",
            "Google",
            "Amazon",
            "Nvidia",
        ]
    whitelist_grouped = [
            "apple",
            "microsoft",
            "google",
            "amazon",
            "nvidia",
        ]
    whitelist_stacked = ["POSITIVE", "NEGATIVE", "NEUTRAL"]  # List of sentiment types

    date_hits = get_daily_hits_breakdown(solr, whitelist=whitelist)    
    stack_bar = plot_stacked_bar_chart(date_hits, whitelist)
    word_frequencies, _ = get_facets(solr, whitelist=whitelist, filter="stopwords")
    wordcloud_fig = create_wordcloud(word_frequencies)
    data = create_sentiment_grouped_stacked(solr, whitelist_grouped=whitelist_grouped, whitelist_stacked=whitelist_stacked)
    whitelist = [
            "apple",
            "microsoft",
            "google",
            "amazon",
            "nvidia",
        ]
    q = "*:*"  # Default query to retrieve all documents
    facet_field = "Sentiment"  # Field to facet on
    whitelist_field = "Description"  # Field to use for whitelist
    
    pie_chart = create_wf_pie_chart(word_frequencies, whitelist)
    bar_chart = create_wf_bar_chart(word_frequencies)
    senti_stack = plot_stock_sentiment(data)
    return stack_bar, wordcloud_fig, pie_chart, senti_stack

def spell_check(text):
    # Create a SpellChecker instance
    spell = Speller(lang='en')

    # Split the text into words
    words = text.split()

    # Correct misspelled words
    corrected_text = []
    for word in words:

        # Get the corrected version of the word
        corrected_word = spell(word)
        corrected_text.append(corrected_word)
    
    # Join the corrected words back into a string
    return ' '.join(corrected_text)        

def has_nonEnglish(text):
    # Define a regular expression pattern for matching Chinese characters
    pattern = re.compile(r'[^a-zA-Z0-9\s.,!?_]')
    
    # Search for the pattern in the text
    match = re.search(pattern, text)
    
    # Return True if a match is found, indicating presence of Chinese characters
    return match is not None

def translate_to_english(text):
    #if has_nonEnglish(text):
    translator = Translator()
    translated_text = translator.translate(text, dest='en')
    return translated_text.text
    return text

def synonym_antonym_extractor(phrase):
     synonyms = []
     antonyms = []

     for syn in wordnet.synsets(phrase):
          for l in syn.lemmas():
               synonyms.append(l.name())
               if l.antonyms():
                    antonyms.append(l.antonyms()[0].name())
     return list(set(synonyms)), list(set(antonyms))

def search(solr, q="*:*", rows=10):
    params = {"q": q, "rows": rows}
    results = solr.search(**params)
    return results.docs

def get_daily_hits(dates, q="*:*"):
    daily_hits = {}
    for date in dates:
        query = f"Posted:[{date} TO {date}]"
        if q != "*:*" and q is not None:
            query = f"({query}) AND ({q})"
        daily_hits[date] = get_hits(solr, query)
    return daily_hits

def get_daily_facets(solr, q="*:*", facet_field="Description", whitelist=None):
    dates = get_dates_with_count(solr, q)
    daily_facets = {date: {} for date in dates}
    for date in dates:
        query = f"Posted:[{date} TO {date}]"
        if q != "*:*" and q is not None:
            query += f" AND ({q})"
        word_frequencies, _ = get_facets(
            solr,
            whitelist_query=query,
            facet_field=facet_field,
            whitelist=whitelist,
            filter="whitelist",
        )
        daily_facets[date] = word_frequencies
    return daily_facets

def plot_bar_chart(
    daily_facets, title="Daily Document Count", xaxis_title="Date", yaxis_title="Count"
):
    fig = go.Figure()
    fig.add_trace(go.Bar(x=list(daily_facets.keys()), y=list(daily_facets.values())))
    fig.update_layout(title=title, xaxis_title=xaxis_title, yaxis_title=yaxis_title)
    return fig

def get_docs(solr, q="*:*", max_rows=None):
    params = {"q": q}
    if max_rows is not None:
        params["rows"] = max_rows
    results = solr.search(**params)
    return results.docs

SYNONYMS = {
            "aapl": "apple",
            "msft": "microsoft",
            "googl": "google",
            "goog": "google",
            "amzn": "amazon",
            "tsla": "tesla",
            "nvda": "nvidia",
            "nasdaq:msft": "microsoft",
            "nasdaq:aapl": "apple",
            "nasdaq:goog": "google",
            "nasdaq:amzn": "amazon",
            "nasdaq:tsla": "tesla",
            "nasdaq:nvda": "nvidia",
            "alphabet": "google",
            "amazon.com": "amazon",
            "google's": "google",
            "amazon's": "amazon",
            "apple's": "apple",
        }

stop_words = set(stopwords.words("english"))
custom_stop_words = {
            "llc",
            "inc",
            "corp",
            "company",
            "also",
            "stock",
            "shares",
            "share",
            "including",
            "use",
            "it's",
            "look",
            "said",
            "lifted",
            "company's",
        }

stop_words.update(custom_stop_words)
solr  = pysolr.Solr('http://localhost:8983/solr/stocks_core2', always_commit=True)
stack_bar, wordcloud_fig, pie_chart, senti_stack = preload(solr)

response = solr.search("testtt")
st.title('Stocks News Query')
st.sidebar.header('Query Finder')

options = ['Search', 'About database']
display = st.sidebar.selectbox('Display', options)
custom_query = st.sidebar.text_input('Search bar', '')
if custom_query:
    custom_query1 = translate_to_english(custom_query)

else:
    custom_query1 = "*:*"
# Button to trigger the query
search_button_col, query_col = st.columns([1, 4])
with search_button_col:
    search_button = st.sidebar.button('Search')

start_date = str(st.sidebar.date_input('Start date', value=datetime.date(2024, 2, 16)))
end_date = str(st.sidebar.date_input('End date', value=datetime.date(2024, 3, 31)))

options = ['asc', 'desc']

# Display the dropdown menu
asc = st.sidebar.selectbox('Sort date', options)

if(display == 'About database'):
    st.subheader('About database')
    with st.spinner("Generating stacked bar chart..."):
        st.plotly_chart(stack_bar)
    st.write('')
    with st.spinner("Generating word cloud..."):
        st.plotly_chart(wordcloud_fig)
    st.write('')
    with st.spinner("Generating pie chart..."):
        st.plotly_chart(pie_chart)
    st.write('')
    with st.spinner("Generating sentiment stacked bar chart..."):
        st.plotly_chart(senti_stack)

# Execute the query when the search button is clicked
if search_button:
    if(display == 'Search'):
        # Display the results
        st.header('Search Results for ' + custom_query)
        
        start_time = time.time()
        response = solr.search('Headline:\"'+custom_query1 + "\" AND Posted:[\"" + start_date + "T00:00:00Z\"" + " TO \"" + end_date + "T23:59:59Z\"]" ,**{'start': 0, 'rows': 20000, 'sort':'Posted ' + asc})
        st.write("Found " + str(len(response)) + " results in " +str(round((time.time() - start_time),5)) + " seconds")
        if len(custom_query1.split())==1:
            syn, ant = synonym_antonym_extractor(phrase=custom_query1)
            suggest = "*Synonyms:"
            if len(syn) > 3:
                for i in range(4):
                    if syn[i] != custom_query1:
                        suggest = suggest + "  " + syn[i]
                        
                suggest += "*"
                st.write(suggest)
            suggest = "*Antonyms:"
            if len(ant) > 0:
                for i in range(len(ant)):
                    if ant[i] != custom_query1:
                        suggest = suggest + "  " + ant[i]
                        
                suggest += "*"
                st.write(suggest)

        count = 1
        if custom_query1.lower() == "apple":
            st.image("https://cdn.dribbble.com/users/1161517/screenshots/7896076/media/24ae74ddb6c9eb7789ae3a189a6b30ae.gif", width=200)
        elif custom_query1.lower() == "google":
            st.image("https://i.kym-cdn.com/photos/images/newsfeed/002/052/110/0e1.gif")
        elif custom_query1.lower() == "nvidia":
            st.image("https://cdn.dribbble.com/userupload/4297888/file/original-e73618428a72133a58c0dbec1c913e5f.gif", width=200)
        elif custom_query1.lower() == "microsoft":
            st.image("https://cdn.dribbble.com/users/2100764/screenshots/5549274/media/ba14aea382f73f261df3e1f35b838890.gif", width=200)
        elif custom_query1.lower() == "amazon":
            st.image("https://cdn.dribbble.com/users/954572/screenshots/16765270/amazon-gif.gif", width=200)
        
        positive_count = 0
        negative_count = 0
        neutral_count = 0
        for hit in list(response):
            st.write("------------------------------------------------ Result " + str(count) + " ------------------------------------------------")
            st.subheader(hit['Headline'][0])
            st.write("Dated: " + hit['Posted'][0][:10])
            Sentiment = hit['Sentiment'][0]
            if Sentiment == 'POSITIVE':
                st.markdown(f'Sentiment:  <font color="green">{Sentiment}</font>', unsafe_allow_html=True)
                positive_count += 1
            elif Sentiment == 'NEGATIVE':
                st.markdown(f'Sentiment:  <font color="red">{Sentiment}</font>', unsafe_allow_html=True)
                negative_count += 1
            else:
                st.write("Sentiment: " + Sentiment) 
                neutral_count += 1
                
            
            st.write(hit['Description'][0] + " " +"[(Read more...)](hit['Link'][0])")
            st.write("Source: " + hit['Source'][0])  
            st.write("Link: " + hit['Link'][0])
            
            count +=1

        count = 1
        if len(response) < 5 and spell_check(custom_query1) != custom_query1:

            st.subheader('Did you mean: ' + '*' + spell_check(custom_query1) + '*')
            st.header('Search Results for ' + spell_check(custom_query1))
            start_time = time.time()
            response = solr.search('Headline:\"'+spell_check(custom_query1) + "\" AND Posted:[\"" + start_date + "T00:00:00Z\"" + " TO \"" + end_date + "T23:59:59Z\"]" ,**{'start': 0, 'rows': 20000, 'sort':'Posted ' + asc})
            st.write("Found " + str(len(response)) + " results in " +str(round((time.time() - start_time),5)) + " seconds")
            
            positive_count = 0
            negative_count = 0
            neutral_count = 0
            for hit in response:
                st.write("------------------------------------------------ Result " + str(count) + " ------------------------------------------------")
                st.subheader(hit['Headline'][0])
                st.write("Dated: " + hit['Posted'][0][:10])
                Sentiment = hit['Sentiment'][0]
                if Sentiment == 'POSITIVE':
                    st.markdown(f'Sentiment:  <font color="green">{Sentiment}</font>', unsafe_allow_html=True)
                    positive_count += 1
                elif Sentiment == 'NEGATIVE':
                    st.markdown(f'Sentiment:  <font color="red">{Sentiment}</font>', unsafe_allow_html=True)
                    negative_count += 1
                else:
                    st.write("Sentiment: " + Sentiment) 
                    neutral_count += 1
                st.write(hit['Description'][0] + " " + "[Read more...](hit['Link'][0])")
                st.write("Source: " + hit['Source'][0])  
                st.write("Link: " + hit['Link'][0])
                if hit['Sentiment'] == 'POSITIVE':
                    positive_count += 1
                elif hit['Sentiment'] == 'NEGATIVE':
                    negative_count += 1
                else:
                    neutral_count += 1
                
                count +=1

    st.sidebar.markdown(f'Positive Count:  <font color="green">{positive_count}</font>', unsafe_allow_html=True)

    st.sidebar.markdown(f'Negative Count:  <font color="red">{negative_count}</font>', unsafe_allow_html=True)

    st.sidebar.markdown(f'Neutral Count: {neutral_count}')