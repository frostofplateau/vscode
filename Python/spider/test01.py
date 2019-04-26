#-*- encoding:utf-8 -*-
import urllib.request
import ssl

url = "http://www.baidu.com"
context = ssl._create_unverified_context()
headers = {"User-Agent": "ad"}
request = urllib.request.Request(url, headers=headers)
response = urllib.request.urlopen(request, context=context)
html = response.read().decode("utf-8")
print(type(html))
with open("a.html", 'w', encoding="utf-8") as f:
    f.write(html)
"""
这句会出错
print(html)
原因：
由于本地系统是Win7中的cmd，默认codepage是CP936，即GBK的编码，所以需要先将上述的Unicode的titleUni先编码为GBK，
然后再在cmd中显示出来，然后由于titleUni中包含一些GBK中无法显示的字符，
导致此时提示“’gbk’ codec can’t encode”的错误的
"""
