import urllib.request



url = "https://sh.fang.anjuke.com/loupan/all/p1/"
request = urllib.request.Request(url)
response = urllib.request.urlopen(request).read()
print(response)
