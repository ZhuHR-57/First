#include"queue.h"

static void CopyToNode(int item,Node * pn){
    pn->item = item;
}

static void CopyToItem(Node * pn,int * pi){
    *pi = pn->item;
}

/*操作 ：                  初始化一个链表*/
/*前提条件 ：          pq指向一个链表*/
/*后置条件：          链表初始化为空*/
void InitializeQueue(Queue *pq){
    pq->front = pq->rear = NULL;
    pq->items = 0;
}

/*操作 ：                                        检查队列是否已满*/
/*前提条件 ：                                    pq指向一个链表*/
/*后置条件：          如果为满返回true;否则返回false*/
bool QueueIsFull(const Queue *pq){
    return pq->items == MAXQUEUE;
}

/*操作 ：                                        检查队列是否为空*/
/*前提条件 ：                                    pq指向一个链表*/
/*后置条件：          如果为空返回true;否则返回false*/
bool QueueIsEmpty(const Queue *pq){
    return pq->items == 0;
}

/*操作 ：                                        确定队列中的项数*/
/*前提条件 ：                                    pq指向一个链表*/
/*后置条件：                                返回队列 中的项数*/
int QueuetItemCount(const Queue *pq){
    return pq->items;
}

/*操作 ：                                                                               在队列末尾添加项*/
/*前提条件 ：                                                                           pq指向一个链表*/
/*                                                                         item是要被添加到末尾的项数*/
/*后置条件：如果队列不为空，则添加项到末尾，返回false，否则返回itrue*/
bool EnQueue(int item,Queue *pq){
    Node * pnew;

    if(QueueIsFull(pq))
        return false;
    pnew = (Node*)malloc(sizeof(Node));
    if(pnew == NULL)
    {
        fprintf(stderr,"Unable to allocate memory!\n");
        exit(EXIT_FAILURE);
    }
    CopyToNode(item,pnew);
    if(QueueIsEmpty(pq))
    pnew->next = pnew;
    else
        pq->rear->next = pnew;
    pq->rear = pnew;
    pq->items++;

    return true;
}


/*操作 ：                                                                                    从队列中删除项*/
/*前提条件 ：                                                                            pq指向一个链表*/
/*后置条件：   如果队列不为空，则将首端item拷贝到*pitem中，并删除首端*/
/*                                                          如果该操作使得首端为空，则重置队列*/
/*                                                                         如果在操作前为空则返回false*/
bool DeQueue(int *pitem,Queue *pq){
    Node * pt;

    if(QueueIsEmpty(pq))
        return false;
    CopyToItem(pq->front,pitem);
    pt = pq->front;
    pq->front = pq->front->next;
    free(pt);
    pq->items--;
    if(pq->items == 0)
        pq->rear =NULL;

    return true;
}

/*操作 ：                         释放已分配的内存*/
/*前提条件 ：  pq指向一个已初始化的链表*/
/*后置条件：          释放后，队列设置为空*/
void  EmptyTheQueue( Queue *pq){
    int dummy;
    while(!QueueIsEmpty(pq))
        DeQueue(&dummy,pq);
}

