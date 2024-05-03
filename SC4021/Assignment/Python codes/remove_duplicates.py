import pandas as pd

df = pd.read_csv('C:\\Users\\ZW\\Desktop\\Stocks31MarWaddedStuff\\model training\\combined_online_sentimentFormatted_38997values.csv')

# Define subset of columns to check for duplicates
subset_columns = ['Text','Sentiment']

# Drop duplicate rows based on subset of columns
df.drop_duplicates(subset=subset_columns, keep='first', inplace=True)

# Save the DataFrame to a new csv file
df.to_csv('C:\\Users\\ZW\\Desktop\\Stocks31MarWaddedStuff\\model training\\combined_online_sentiment_dupDropped.csv', index=False)