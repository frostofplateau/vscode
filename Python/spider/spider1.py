import urllib.request
import urllib.parse

def loadPage(url, filename):
    ag_header = {'User-Agent':"adc"}
    request = urllib.request.Request(url,headers=ag_header)
    response = urllib.request.urlopen(request)
    html = response.read()
    html = html.decode("utf-8")
    print("正在下载" + filename)
   
    return html


def writePage(html, filename):
    print("正在保存..." + filename)
    with open(filename, 'w', encoding='utf-8') as f:
        f.write(html)


def spiderPage(url, begainPage, endPage):
    for page in range(begainPage, endPage+1):
        pn = (page-1) * 50
        filename = "第" + str(page) + "页.html"
        fullurl = url + "&pn=" + str(pn)
        html = loadPage(fullurl, filename)
        writePage(html, filename)

if __name__ == "__main__":
    keyword = input("please enter your keyword:")
    beaginPage = int(input("enter begin page:"))
    endPage = int(input("enter end page:"))

    url = "http://tieba.baidu.com/f?"
    
    kw = urllib.parse.urlencode({"keyword":keyword})
    
    print(type(kw))
    fullurl = url + kw
    spiderPage(fullurl, beaginPage, endPage)
