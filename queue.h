#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXQUEUE 10

typedef struct node
{
    int item;
    struct node *next;
}Node;

typedef struct queue
{
    Node * front;//指向头
    Node * rear;//指向尾
    int items;//队列中的项数
}Queue;

/*操作 ：                  初始化一个链表*/
/*前提条件 ：          pq指向一个链表*/
/*后置条件：          链表初始化为空*/
void InitializeQueue(Queue *pq);

/*操作 ：                                        检查队列是否已满*/
/*前提条件 ：                                    pq指向一个链表*/
/*后置条件：          如果为满返回true;否则返回false*/
bool QueueIsFull(const Queue *pq);

/*操作 ：                                        检查队列是否为空*/
/*前提条件 ：                                    pq指向一个链表*/
/*后置条件：          如果为空返回true;否则返回false*/
bool QueueIsEmpty(const Queue *pq);

/*操作 ：                                        确定队列中的项数*/
/*前提条件 ：                                    pq指向一个链表*/
/*后置条件：                                返回队列 中的项数*/
int QueuetItemCount(const Queue *pq);

/*操作 ：                                                                               在队列末尾添加项*/
/*前提条件 ：                                                                           pq指向一个链表*/
/*                                                                         item是要被添加到末尾的项数*/
/*后置条件：如果队列不为空，则添加项到末尾，返回false，否则返回itrue*/
bool EnQueue(int item,Queue *pq);

/*操作 ：                                                                                    从队列中删除项*/
/*前提条件 ：                                                                            pq指向一个链表*/
/*后置条件：   如果队列不为空，则将首端item拷贝到*pitem中，并删除首端*/
/*                                                          如果该操作使得首端为空，则重置队列*/
/*                                                                         如果在操作前为空则返回false*/
bool DeQueue(int *pitem,Queue *pq);

/*操作 ：                         释放已分配的内存*/
/*前提条件 ：  pq指向一个已初始化的链表*/
/*后置条件：          释放后，队列设置为空*/
void  EmptyTheQueue( Queue *pq);