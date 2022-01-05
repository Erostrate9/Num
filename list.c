
#include <stdlib.h>
#include "list.h"

// -----------------------------------------------------------------------------

static Link* get_link(Int n, Int x)
{
    // 初始化双向链表节点
    Link* link = (Link*)malloc(sizeof(Link));
    link->n     = n;
    link->x     = x;
    link->prior = link->next = 0;
    return link;
}

// -----------------------------------------------------------------------------

List* get_list(void)
{
    // 在此处补充完整
    // 初始化双向链表list，size：list中储存的link节点数量。head：指向链表头。tail：指向链表尾
    List* list = (List*)malloc(sizeof(List));
    list->size=0;
    list->head=0;
    list->tail=0;
    return list;
}

void insert_front(List* list, Int n, Int x)
{
    // 在此处补充完整
    // 头插
    Link* newHead = get_link(n,x);
    if(list->head==NULL){
        list->head=newHead;
        list->tail=newHead;
    }else{
        list->head->prior=newHead;
        newHead->next = list->head;
        list->head = newHead;
    }
    list->size++;
}

void insert_back(List* list, Int n, Int x)
{
    // 在此处补充完整
    // 尾插
    Link* newTail = get_link(n,x);
    newTail->prior = list->tail;
    if(list->tail==NULL){
        list->head=newTail;
        list->tail=newTail;
    }else{
        list->tail->next=newTail;
        list->tail=newTail;
    }
    list->size++;
}

void remove_front(List* list)
{
    // 在此处补充完整
    // 删除头部
    if (list==NULL||list->size<1)
        return;

    Link* p = list->head;
    list->head = list->head->next;
    list->head->prior=NULL;
    free(p);
    list->size--;
}

void bubble_sort_x(List* list)
{
    // 在此处补充完整
    // 以x为key对双向链表list进行冒泡升序排序
    //判空
    if (list==NULL || list->size<=1)
    {
        return;
    }

    //初始化辅助指针
    Link *pPre = list->head;
    Link *pCurrent = list->head;
//  //循环次数
    int num = list->size;
    int i,j;
    for (i = 1; i < num; i++)
    {
        //重置指针位置
        pPre = list->head;
        pCurrent = pPre->next;
        for (j = 1; j <= num-i; j++)/*循环条件*/
        {

            if(pPre->x > pCurrent->x)
            {
                if (pCurrent->next==NULL)     //节点尾节点情况
                {
                    pPre->next = pCurrent->next;
                    pCurrent->prior = pPre->prior;
                    pCurrent->next = pPre;
                    pPre->prior->next = pCurrent;
                    pPre->prior = pCurrent;
                    break;
                }
                if (pPre->prior==NULL)     //节点头节点情况
                {
                    list->head =  pCurrent;
                    //pPre与新前驱建立联系
                    /*pPre->prior->next = pCurrent;*/
                    pCurrent->prior = pPre->prior;

                    //pCurrent与新后驱建立联系
                    pCurrent->next->prior = pPre;
                    pPre->next = pCurrent->next;

                    //pPre与pCurrent互连
                    pPre->prior = pCurrent;
                    pCurrent->next = pPre;

                    //pCurrent指针后移到pPre前面
                    pCurrent = pPre->next;
                    continue;
                }

                //非尾节点情况
                //交换节点
                //指针转换	此处注意6个指针交换
                //pPre与新前驱建立联系
                pPre->prior->next = pCurrent;
                pCurrent->prior = pPre->prior;

                //pCurrent与新后驱建立联系
                pCurrent->next->prior = pPre;
                pPre->next = pCurrent->next;

                //pPre与pCurrent互连
                pPre->prior = pCurrent;
                pCurrent->next = pPre;

                //pCurrent指针后移到pPre前面
                pCurrent = pPre->next;
            }
                //pPre->x > pCurrent->x非真情况下
            else
            {
                pPre = pPre->next;
                pCurrent = pCurrent->next;
            }
        }
    }
}

void list_free(List* list)
{
    if (list==NULL)
        return;

    Link* link = list->head;
    while (link) {
        Link* p = link;
        link = link->next;
        free(p);
    }
    free(list);
}

// -----------------------------------------------------------------------------
