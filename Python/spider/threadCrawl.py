import requests
from lxml import etree
from queue import Queue
import threading
import time
import json


class crawlThread(threading.Thread):
    def __init__(self, pageQueue, dataQueue, crawlName):
        super(crawlThread, self).__init__()
        self.pageQueue = pageQueue
        self.dataQueue = dataQueue
        self.crawlName = crawlName
        self.headers = {"User-Agent" : "Mozilla/5.0 (compatible; MSIE 9.0; Windows NT 6.1; Trident/5.0;"}
    def run(self):
        print("start " + self.crawlName)
        while not CRAWL_EXIT:
            try:
                page = self.pageQueue.get(False)
                print("page:%d" %page)
                url = "https://www.qiushibaike.com/text/page/" + str(page) + "/"
                response = requests.get(url, headers=self.headers).text
                time.sleep(1)
                self.dataQueue.put(response)
            except:
                pass
        print("end " + self.crawlName)


class parseThread(threading.Thread):
    def __init__(self, dataQueue, parseName, fileName, lock):
        super(parseThread, self).__init__()
        self.dataQueue = dataQueue
        self.parseName = parseName
        self.fileName = fileName
        self.lock = lock


    def run(self):
        print("start " + self.parseName)
        while not PARSE_EXIT:
            try:
                data = self.dataQueue.get(False)
                self.parse(data)
            except:
                pass
        print("end "+self.parseName)


    def parse(self, html):
        html_dom = etree.HTML(html)
        node_list = html_dom.xpath('//div[contains(@id,"qiushi_tag_")]')
        dic1 = {}
        for node in node_list:
            username = node.xpath('./div//a/h2/text()')
            if username != []:
                username = username[0]
            username = username[1:-1]
            print("username：" + username)
            content = node.xpath('.//div[@class="content"]/span')[0].text
            dic1={
                "username": username,
                "content": content
            }
            with self.lock:
                self.fileName.write(json.dumps(dic1, ensure_ascii=False) + '\n')
                
    
CRAWL_EXIT = False
PARSE_EXIT = False


def main():

    pageQueue = Queue(20)
    for i in range(1,21):
        pageQueue.put(i)
    dataQueue = Queue()
    fileName = open("duanzi.json", 'a')
    lock = threading.Lock()

    crawlName = ["crawl1", "crawl2", "crawl3"]
    crawlList = []
    for name in crawlName:
        crawl_thread = crawlThread(pageQueue, dataQueue, name)
        crawl_thread.start()
        crawlList.append(crawl_thread)

    parseName = ["parse1", "parse2", "parse3"]
    parseList =[]
    for name in parseName:
        parse_thread = parseThread(dataQueue, name, fileName, lock)
        parse_thread.start()
        parseList.append(parse_thread)

    while not pageQueue.empty():
        pass

    global CRAWL_EXIT
    CRAWL_EXIT = True

    print("pagequeue is empyt")
    for thread in crawlList:
        thread.join()
        print("1")

    while not dataQueue.empty():
        pass

    global PARSE_EXIT
    PARSE_EXIT= True

    print("dataqueue is empty")
    for thread in parseList:
        thread.join()
        print("2")

    with lock:
        fileName.close()
    print("THANKS")

if __name__ == "__main__":
        main()
