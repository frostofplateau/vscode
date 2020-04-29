//
//  Link_List.h
//  数据结构
//
//  Created by Peng Wang on 2020/2/21.
//  Copyright © 2020 Peng Wang. All rights reserved.
//

#ifndef Link_List_h
#define Link_List_h

#include <stdio.h>
//节点结构
typedef struct Node{
    int data;
    struct Node* next;
}Link_Node;
//链表的结构
typedef struct Link_List{
    Link_Node* head;
    int size;
}Link_List;
//chushihua
Link_List* InitLinklist(void);
//增
void AddElemToLinklist(Link_List *list,int, int elem);
//查
void FindElemInLinklist(Link_List *list,int elem);
//删
void DelElemFromLinklist(Link_List *list,int elem);
void printData(Link_List *list);
void freeMemory(Link_List *list);
#endif /* Link_List_h */
