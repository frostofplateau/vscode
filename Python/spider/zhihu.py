from bs4 import BeautifulSoup
import requests

def zhihu():
    ag_headers = {"User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/69.0.3497.100 Safari/537.36"}
    sess = requests.Session()
    html = sess.get("https://www.zhihu.com/signin?next=%2F", headers=ag_headers).text
    bs = BeautifulSoup(html, "lxml")
    passwd = bs.find("input", attrs={"name":"password"}).get("class")
    print(passwd)
if __name__ == "__main__":
    zhihu()
