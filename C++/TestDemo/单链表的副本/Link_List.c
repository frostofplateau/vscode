//
//  Link_List.c
//  数据结构
//
//  Created by Peng Wang on 2020/2/21.
//  Copyright © 2020 Peng Wang. All rights reserved.
//

#include "Link_List.h"
#include <stdlib.h>

Link_List* InitLinklist()
{
    Link_List* list = (Link_List*)malloc(sizeof(Link_List));
    list->size = 0;
    list->head->data = NULL;
    list->head->next = NULL;
    return  list;
}
//增
void AddElemToLinklist(Link_List *list, int pos, int elem){
    if(list == NULL)
        return;
    /*
     if(elem == NULL)
        return;
     */
    if(pos < 0 || pos > list->size)
    {
        pos= list->size;
    }
    
    Link_Node* newNode = (Link_Node*)malloc(sizeof(Link_Node));
    newNode->data = elem;
    newNode->next = NULL;
    Link_Node* pCurrent = list->head;
    int i =0;
    while(pCurrent != NULL && i < pos-1)
    {
        //pos前一个节点
        pCurrent = pCurrent->next;
        i++;
    }
    newNode->next = pCurrent->next;
    pCurrent->next = newNode;
    list->size++;
}

//查
void FindElemInLinklist(Link_List *list,int elem){
    Link_Node* pCurrent = list->head;
    int i = 0;
    while(pCurrent->next != NULL && pCurrent->data != elem){
        pCurrent = pCurrent->next;
        i++;
    }
    if(pCurrent->next == NULL)
    {
        printf("not find");
    }
    else{
        printf("it's in %d.", i);
    }
}

//删
void DelElemFromLinklist(Link_List *list,int elem){
    if(list->size <= 0){
        printf("linklist is empty");
    }else{
        Link_Node* pPre = list->head;
        Link_Node* pCurrent = pPre->next;
        int i = 0;
        while(pCurrent->next != NULL && pCurrent->data != elem){
            pCurrent = pCurrent->next;
            pPre = pPre->next;
            i++;
        }
        if(pCurrent->next == NULL)
        {
            printf("not find");
        }
        else{
            pPre->next = pCurrent->next;
            free(pCurrent);
            printf("deleted!");
        }
    }
}

void printData(Link_List *list){
    if(list->size == 0){
        printf("list is empty!");
    }
    else{
        Link_Node * pCurrent = list->head;
        printf("linklist elems is:");
        while(pCurrent->next != NULL){
            pCurrent = pCurrent->next;
            printf("%d ", pCurrent->data);
        }
        printf("\n");
    }
}

void freeMemory(Link_List *list){
    if(list == NULL){
        printf("linklist was empty!");
        return;
    }
    Link_Node * pCurrent = list->head;
    while (pCurrent->next != NULL) {
        Link_Node *pNext = pCurrent->next;
        free(pCurrent);
        pNext = pCurrent;
    }
}
