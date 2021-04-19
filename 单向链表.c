```c
//some notes about Link learning
//by shouxindehai.cn
//first creat 2020-12-21-18

#include<stdio.h>
#include<stdlib.h>
//定义链表结构
typedef struct ListNode
{
    int element;
    struct ListNode *next;
    
}Node;
//定义链表指针
typedef struct ListNode* Link;

//initList
void initList(Link pNode)
{
    pNode=NULL;
}
//creatList
Link creat(char *p)
{
    Link head=NULL;
    if(*p=='\0')
    {
        return  NULL;
    }else{
        head=(Link)malloc(sizeof(Node));
        head->element=*p;
        head->next=creat(p+1);
        return head;
    }
}
//printList
void printList(Link head)
{
    Link temp=head;
    while(temp)
    {
        printf("%d",temp->element);
        temp=temp->next;
    }
}
//lenofList
int size_List(Link head)
{
    int size=0;
    Link temp=head;
    while(temp)
    {
        size++;
        temp=temp->next;
    }
    return size;
}
//插入节点
Link insert(Link head,char mark)
{
    Link temp=head,last,new;
    Link pRecord=head;
    new=(Link)malloc(sizeof(Link));
    new->data=mark;
    new->next=NULL;
    int min=9999999;
    while(temp)
    {
        if(abs(temp->data-mark)<min)
        {
            min=abs(temp->data-mark);
            pRecord=temp;
        }
        temp=temp->next;
    }
    temp=head;
    while(temp)
    {
        if(temp==pRecord)
        {
            new->next=temp->next;
            temp->next=new;
            break;
        }
        temp=temp->next;
    }
    return head;
}
//deldete
Link delete(node *pNode,char mark)
{
    node *pMovePre;
    node *pMove;
    pMovePre=pNode;
    pMove=pNode->next;
    Link temp=pMovePre;
    while(pMove)
    {
        
        if(pNode->data==mark)
        {
            temp=pMovePre;
            pNode=pNode->next;
            flag=1;
        }else{
            if(pMovePre->data==mark)
            {
                temp->next=pMove;
                free(pMovePre);
                flag=1;
            }else{
                temp=pMovePre;
            }
        }
        pMovePre=pMove;
        pMove=pMove->next;
    }
    return pNode;
}

```

