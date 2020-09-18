//
//  main.c
//  数据结构
//
//  Created by Peng Wang on 2020/2/22.
//  Copyright © 2020 Peng Wang. All rights reserved.
//

#include <stdio.h>
#include "Link_List.h"
void test01()
{
    Link_List *list;
    list = InitLinklist();
    //增
    AddElemToLinklist(list,2, 3);
    printData(list);
    //查
    FindElemInLinklist(list,3);
    //删
    DelElemFromLinklist(list,2);
    printData(list);
    freeMemory(list);
}
int main()
{
    test01();
}
