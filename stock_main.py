from nytimesarticle import articleAPI
import json
from pprint import pprint
from collections import defaultdict
import string
'''from lxml import html
import requests
import urllib
import re'''

############### NYTIMES API LOGIC ###################
api = articleAPI('e4ec2febf01140cf80540ae9b73f7fe8')
stockName = raw_input("Enter the stock name:")
stockFile = open(stockName +".txt", "w")
page_num = 0
articles = {}
while page_num < 10:
    articles = api.search( q = stockName, fq = {'headline':stockName, 'source':['Reuters','AP', 'The New York Times']}, begin_date = 20160525,fl = 'headline,pub_date,web_url',page=page_num)
    page_num += 1
    stockFile.write(str(articles))
d = defaultdict(int)
for word in str(articles).split():
    d[word] += 1

############# APP LOGIC ##################
stockFile = open(stockName +".txt") #Open file with all the nytimes API info
stockList = stockFile.readlines()

percentFile = open("percentage.txt") #Open file with all the stock information
percentList = percentFile.readlines() #current format Percent Change Date

# creates a dictionary and fills it with data from percentage.txt
# dictionary format { Date : Percent }
percentDict = {}
for line in percentList:
    percent, date = line.split(' ', 1)
    percentDict[date] = percent

#get headlines with their corresponding dates
docs =  articles["response"]["docs"] #from nytimes API
headline_dates = []
headlines = {}
for i in docs:
    headline_dates = i["pub_date"]
    newHeadlineDates = i["pub_date"][:10] #get date published from nytimes API
    for sDate, sPercent in percentDict.iteritems(): #iterate through percent Dictionary
        finalDate = str(sDate)[:10]
        if str(newHeadlineDates) == finalDate: #if headline date = stock date then add 1 entry to headlines array
            #print i["headline"]["main"]
            #print i["pub_date"]
            headlines[i["headline"]["main"]] = finalDate #current format {headline,date}


wordFile = open("wordFile.txt","w") # create a new file to store final data
words = []
split_words = ""


for my_word, my_date in headlines.iteritems(): #iterate through headlines
    split_words = my_word.split(' ')
    for each_word in split_words: #iterate through the headlines
        each_word = each_word + " " +  str(my_date) + " " + percentDict[my_date+'\n'] + "\n" #create the output string in the format word date percent change
        #removing extra characters from final output
        newString = (each_word).replace(',', '')
        finalString = (newString).replace(';', '')
        
        #finally writing to final output file
        wordFile.write(each_word)



