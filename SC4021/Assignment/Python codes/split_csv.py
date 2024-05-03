import pandas as pd

chunk_size = 600000

file_counter = 0

for chunk in pd.read_csv('C:\\Users\\ZW\\Desktop\\Stocks31MarWaddedStuff\\model training\\Datasets\\0neg2neu4pos.csv', chunksize=chunk_size,encoding='latin1'):
    filename = f'C:\\Users\\ZW\\Desktop\\Stocks31MarWaddedStuff\\model training\\Datasets\\0neg2neu4pos_{file_counter}.csv'
    
    chunk.to_csv(filename,index=False)

    file_counter+=1