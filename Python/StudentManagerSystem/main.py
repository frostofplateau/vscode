import re
import menu

import insert
import search
import delete
import modify
import sort
import total
import show


def main():
    ctrl = True                                             # 标记是否退出系统
    while(ctrl):
        menu.menu()
        option = input("请选择：")
        option_str = re.sub('\D', '', option)               # 提取数字
        if option_str in ['0', '1', '2', '3', '4', '5', '6', '7']:
            option_int = int(option_str)
            if option_int == 0:
                print("您已退出学生管理系统！")
                ctrl = False
            elif option_int == 1:
                insert.insert()
            elif option_int == 2:
                search.search()
            elif option_int == 3:
                delete.delete()
            elif option_int == 4:
                modify.modify()
            elif option_int == 5:
                sort.sort()
            elif option_int == 6:
                total.total()
            elif option_int == 7:
                show.show()

