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
    node_list = html_dom.xpath('//div/ul/li/div[@class="resblock-desc-wrapper"]')
    dic1 = {}
    for node in node_list:
        buildingName = node.xpath('./div[@class="resblock-name"]/a')[0].text
        print(buildingName)
        buildingPrice = node.xpath('./div[@class="resblock-price"]/div[@class="main-price"]/span[1]')[0].text
        # unit = node.xpath('./div[@class="resblock-price"]/div[@class="main-price"]/span[2]')[0].text
        # buildingPrice = buildingPrice + unit
        dic1={
            "buildingName": buildingName,
            "buildingPrice": buildingPrice
        }
        dic = json.dumps(dic1, ensure_ascii=False)
        writeToFile(dic)


def writeToFile(dic):
    with open("链家.json", "a", encoding="utf-8") as f:
        f.write(dic+'\n')


if __name__ == "__main__":
    url = "https://sh.fang.lianjia.com/loupan/"
    for i in range(1,100):
        fullurl = url + "pg" + str(i) + "/"
        spiderProcess(fullurl)