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
    node_list = html_dom.xpath('//div[@class="item-mod"]')
    dic1 = {}
    for node in node_list:
        print(node)
        # buildingName = node.xpath('./div/a/h3/span')[0].text
        buildingName = node.xpath('./div[@class="infos"]/a[@class="lp-name"]/h3/span[@class="items-name"]')[0].text
        print(buildingName)
        # buildingPrice = node.xpath('./a/p/span')[0].text
        buildingPrice = node.xpath('./a[@class="favor-pos"]/p/span')[0].text
        dic1={
            "buildingName": buildingName,
            "buildingPrice": buildingPrice
        }
        dic = json.dumps(dic1, ensure_ascii=False)
        writeToFile(dic)


def writeToFile(dic):
    with open("安居客.json", "a", encoding="utf-8") as f:
        f.write(dic+'\n')


if __name__ == "__main__":
    url = "https://sh.fang.anjuke.com/loupan/all/p"
    for i in range(1,29):
        fullurl = url + str(i) + "/"
        spiderProcess(fullurl)