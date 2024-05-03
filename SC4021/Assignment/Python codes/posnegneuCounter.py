import pandas as pd

df = pd.read_csv('combined_csv_dupDropped_1709labelled.csv')

Sen1_counts = df['Sentiment1'].value_counts()
print("Sentiment 1:")
for value,count in Sen1_counts.items():
    print(value, count)
print("\n")

Sen2_counts = df['Sentiment2'].value_counts()
print("Sentiment 2:")
for value,count in Sen2_counts.items():
    print(value, count)
print("\n")

FINALSen_counts = df['FINAL Sentiment'].value_counts()
print("FINAL Sentiment:")
for value,count in FINALSen_counts.items():
    print(value, count)
print("\n")

