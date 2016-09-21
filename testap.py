
from urllib.parse import urlparse
import newspaper
from newspaper import Article

urlFileRead = open("newspaperURLS.txt","r")
urlRead = urlFileRead.readlines()

urlFileAppend = open("newspaperURLS.txt","a")

cnn_paper = newspaper.build('http://cnn.com')
for article in cnn_paper.articles:
    urlFileAppend.write(article.url)

textfile_url = open("urltextfiles.txt","w")

for urlLine in urlRead:
    first_article = Article(url = urlLine)
    first_article.download()
    print article.html
    first_article.parse()
    print(first_article.publish_date)
    textfile_url.write(first_article.text)

'''  urlFinal = "\"" + urlLine.rstrip() + "\""
    print (urlFinal)'''
