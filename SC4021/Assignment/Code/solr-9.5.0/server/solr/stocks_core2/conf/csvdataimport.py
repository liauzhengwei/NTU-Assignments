import csv
import pysolr

# Connect to solr
solr = pysolr.Solr('http://localhost:8983/solr/stocks_core2', always_commit=True)

print("Connected")

# Read CSV and index documents
with open('C:/Users/liauz/Downloads/solr-9.5.0/solr-9.5.0/server/solr/stocks_core2/conf/combined_csv.csv', 'r', encoding='utf-8') as csvfile:
    print("reading")
    reader = csv.DictReader(csvfile)

    # Create a dictionary to store columns
    columns = {}
    count=0
    # Iterate over rows
    for row in reader:
        # Format data for Solr
        solr_doc = {
            'Index':row.get('Index'),
            'Headline':row.get('Headline'),
            'Source':row.get('Source'),
            'Posted':row.get('Posted'),
            'Description':row.get('Description'),
            'Link':row.get('Link'),
        }
        count+=1
        print(count)
        #Index document
        solr.add([solr_doc])

print("Import complete")