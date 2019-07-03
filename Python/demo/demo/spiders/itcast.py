# -*- coding: utf-8 -*-
import scrapy
from demo.items import DemoItem

class ItcastSpider(scrapy.Spider):
    name = 'itcast'
    allowed_domains = ['itcast.cn']
    start_urls = [
        'http://www.itcast.cn/channel/teacher.shtml',
        'http://www.itcast.cn/channel/teacher.shtml#ajavaee',
        'http://www.itcast.cn/channel/teacher.shtml#aLinux',
        'http://www.itcast.cn/channel/teacher.shtml#anetmarket'
    ]

    def parse(self, response):
        filename = "teacher.html"
        # open(filename, 'w', encoding='utf-8').write(response.body.decode())
        open(filename, 'w', encoding='utf-8').write(response.body.decode('utf-8'))
        # items = []
        for each in response.xpath('//div[@class="li_txt"]'):
            item = DemoItem()
            name = each.xpath("h3/text()").extract()
            title = each.xpath("h4/text()").extract()
            info = each.xpath("p/text()").extract()
            item['name'] = name[0]
            item['title'] = title[0]
            item['info'] = info[0]
            # items.append(item)
        # return items
            yield item