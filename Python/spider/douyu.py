#-*- coding:utf-8 -*-
import unittest
from selenium import webdriver
from bs4 import BeautifulSoup as bs


class douyu(unittest.TestCase):
    """
    处理JS分页加载的网页
    """
    def setUp(self):
        self.driver = webdriver.PhantomJS()


    def testDouyu(self):
        self.driver.get("https://www.douyu.com/directory/all")
        while True:
            soup = bs(self.driver.page_source, "lxml")
            names = soup.find_all("h2", {"class": "DyListCover-user"})
            hots = soup.find_all("span", {"class": "DyListCover-hot"})
            for name, hot in zip(names, hots):
                print("hots:" + hot.get_text().strip() + ",\troom name:" + name.get_text().strip())
            if self.driver.page_source.find("dy-Pagination-disabled dy-Pagination-next") != -1:
                break
            self.driver.find_element_by_class_name(" dy-Pagination-next").click()

    def tearDown(self):
        self.driver.quit()


if __name__ == "__main__":
    unittest.main()