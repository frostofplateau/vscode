from lxml import etree
import urllib.request


def loadPage(url):
    """
    获取url地址
    """
    # http://www.mm131.com/xinggan/
    # 获取首页URL //div[@class="main"]//dd/a/@href
    picreferer = {
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; WOW64; Trident/7.0; rv:11.0) like Gecko",
            'Referer': 'http://www.mm131.com'
    }    
    request = urllib.request.Request(url, headers=picreferer)
    response = urllib.request.urlopen(request)
    html = response.read()
    content = etree.HTML(html)
    picLink_list = content.xpath('//div[@class="main"]//dd/a/@href')
    new_picLink_list = []
    for num in range(0,len(picLink_list)):
        new_picLink_list.append(picLink_list[num])
    for link in new_picLink_list:
        loadLink(link)


def loadLink(url):
    """
    获取图片链接
    """
    picreferer = {
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; WOW64; Trident/7.0; rv:11.0) like Gecko",
            'Referer': 'http://www.mm131.com'
    }
    request = urllib.request.Request(url, headers=picreferer)
    response = urllib.request.urlopen(request)
    html = response.read()
    content = etree.HTML(html)
    picLink_list = content.xpath('//div[@class="content-page"]//span[@class="page-ch"]/text()')
    if picLink_list != []:
        picLink_list = picLink_list[0]
        totalPages = int(picLink_list[1:3])
        print("this group total pictures:" + str(totalPages))
        fullurl_list = [url]
        for num in range(2, totalPages+1):
            fullurl = url[0:-5] + "_" + str(num) + ".html"
            fullurl_list.append(fullurl)
        for item in fullurl_list:
            # print("正在下载图片" + item)
            downloadPic(item)

    
def downloadPic(link):
    # print("xiazai:"+link)
    picreferer = {
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; WOW64; Trident/7.0; rv:11.0) like Gecko",
            'Referer': 'http://www.mm131.com'
    }
    request = urllib.request.Request(link, headers=picreferer)
    response = urllib.request.urlopen(request)
    html = response.read()
    content = etree.HTML(html)

    picLink = content.xpath('//div[@class="content"]//div[@class="content-pic"]//img/@src')[0]
    print("正在下载图片"+picLink)
    filename = content.xpath('//div[@class="content"]/h5/text()')[0]
    fullName  = filename + ".jpg"

    request = urllib.request.Request(picLink, headers=picreferer)
    response = urllib.request.urlopen(request)
    image = response.read()
    with open(fullName, 'wb',) as f:
        f.write(image)
        print("正在保存图片" + fullName)


# def spiderProcess(url):
        """
        这应该是个爬虫调度程序
        """
#     ag_headers = {"User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/69.0.3497.100 Safari/537.36"}
#     request = urllib.request.Request(url, headers=ag_headers)
#     response = urllib.request.urlopen(request)
#     html = response.read()
#     content = etree.HTML(html)
#     picLink = content.xpath('//div[@class="content"]//div[@class="content-pic"]//img/@src')[0]
#     print(picLink)
#     downloadPic(picLink)


if __name__ == "__main__":

    url = "http://www.mm131.com/xinggan/"
    loadPage(url)
#     spiderProcess(url)
    for i in range(2, 189):
        fullurl = url + "list_6_" + str(i) + ".html"
        # spiderProcess(fullurl)
        loadPage(fullurl)
    print("thanks")