# code to combine recent scraped data with the existing data

import pandas as pd

# List of csv file names
csv_files = ['C:\\Users\\ZW\\Desktop\\Stocks31MarWaddedStuff\\model training\\Datasets\\0neg1pos.csv','C:\\Users\\ZW\\Desktop\\Stocks31MarWaddedStuff\\model training\\Datasets\\0neg1pos2neu(1).csv','C:\\Users\\ZW\\Desktop\\Stocks31MarWaddedStuff\\model training\\Datasets\\0neg1pos2neu(2).csv','C:\\Users\\ZW\\Desktop\\Stocks31MarWaddedStuff\\model training\\Datasets\\1pos-1negFormatted.csv','C:\\Users\\ZW\\Desktop\\Stocks31MarWaddedStuff\\model training\\Datasets\\negposneuFormatted.csv',
'C:\\Users\\ZW\\Desktop\\Stocks31MarWaddedStuff\\model training\\Datasets\\github1.csv',
'C:\\Users\\ZW\\Desktop\\Stocks31MarWaddedStuff\\model training\\Datasets\\kaggle1.csv']

# Read each csv file into a DataFrame and concatenate them
dfs = []
for file in csv_files:
    try:
        df = pd.read_csv(file,encoding='utf-8')
    except UnicodeDecodeError:    
        df = pd.read_csv(file,encoding='latin1')
    dfs.append(df)
    
combined_df = pd.concat(dfs,ignore_index=True)

# Save the combined DataFrame to a new csv file
combined_df.to_csv('C:\\Users\\ZW\\Desktop\\Stocks31MarWaddedStuff\\model training\\Datasets\\combined_online_sentiment.csv')

#extra columns removed in csv then further processed with remove_duplicate.py