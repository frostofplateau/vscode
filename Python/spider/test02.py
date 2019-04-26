import urllib.request

http_handler = urllib.request.HTTPHandler()
opener = urllib.request.build_opener(http_handler)
request = urllib.request.Request("http://www.baidu.com")
response = opener.open(request).read().decode("utf-8")
with open("b.html", 'w', encoding="utf-8") as f:
    f.write(response)
