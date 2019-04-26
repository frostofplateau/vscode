import urllib.request
from lxml import etree
import json

def spiderProcess(url):
    """
    have bug
    """
    headers = {"User-Agent": "Mozilla/5.0 (Windows NT 10.0; WOW64; Trident/7.0; rv:11.0) like Gecko"}
    request = urllib.request.Request(url, headers=headers)
    response = urllib.request.urlopen(request).read()
    html_dom = etree.HTML(response)
    node_list = html_dom.xpath('//div[contains(@id,"qiushi_tag_")]')
    dic1 = {}
    for node in node_list:
        username = node.xpath('./div//a/h2/text()')
        if username != []:
            username = username[0]
        username = username[1:-1]
        content = node.xpath('.//div[@class="content"]/span')[0].text
        dic1={
            "username": username,
            "content": content
        }
        dic = json.dumps(dic1, ensure_ascii=False)
        writeToFile(dic)


def writeToFile(dic):
    with open("qiushi.json", "a", encoding="utf-8") as f:
        f.write(dic+'\n')


if __name__ == "__main__":
    url = "https://www.qiushibaike.com/text/page/"
    for i in range(1,13):
        fullurl = url + str(i) + "/"
        spiderProcess(fullurl)
