# -*- coding: utf-8 -*-
import scrapy
from tencent.items import TencentItem


class TencentitemSpider(scrapy.Spider):
    name = 'tencentItem'
    allowed_domains = ['hr.tencent.com']
    url = "https://hr.tencent.com/position.php?lid=&tid=&keywords=%E8%AF%B7%E8%BE%93%E5%85%A5%E5%85%B3%E9%94%AE%E8%AF%8D&start="
    offset = 0
    start_urls = [url+str(offset)]

    def parse(self, response):
        p_list = response.xpath("//tr[@class='even'] | //tr[@class='odd']")
        for each in p_list:
            item = TencentItem()
            positionName = each.xpath('./td[1]/a/text()').extract()
            p_type = each.xpath('./td[2]/text()').extract()
            # print("name:")
            # print(positionName)
            if positionName != []:
                item['positionName'] = positionName[0]
            if p_type != []:
                item['positionType'] = p_type[0]
            yield item
        if self.offset < 3300:
            self.offset += 10
        yield scrapy.Request(self.url+str(self.offset), callback=self.parse)
