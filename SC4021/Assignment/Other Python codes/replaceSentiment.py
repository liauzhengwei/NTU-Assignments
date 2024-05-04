import pandas as pd

data = pd.read_csv('C:\\Users\\ZW\\Desktop\\Stocks31MarWaddedStuff\\model training\\Datasets\\combined_online_sentiment.csv',encoding='latin1')

data['Sentiment'] = data['Sentiment'].replace(['POSITIVE','NEGATIVE','NEUTRAL'], [1,0,2])

data.to_csv('C:\\Users\\ZW\\Desktop\\Stocks31MarWaddedStuff\\model training\\Datasets\\combined_online_sentimentFormatted.csv', index=False)