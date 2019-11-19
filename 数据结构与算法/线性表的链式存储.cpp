#include <iostream>
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define  INFEASIBLE -1
#define OVERFLOW -2
typedef int  Status;
typedef struct
{
    int num;
    char name[8];
    int score;
    
}ElemType;
typedef struct Student
{
    ElemType data;
    struct Student *next;
}Lnode,*LinkList;
//单链表的初始化
Status InitList(LinkList &L)
{
    L=new Lnode;
    L->next=NULL;
    return OK;
}
//判断单链表是否为空
int ListEmpty(LinkList L)
{
    if(L->next)
        return 0;
    else
        return 1;
}
//单链表的销毁
Status DestroyList_L(LinkList &L)
{
    Lnode *p;
    while(L)
    {
        p=L;
        L=L->next;
        delete p;
    }
    return OK;
}
//清空单链表
Status  ClearList(LinkList &L)
{
    Lnode *p;
    Lnode *q;
    p=L->next;
    //-----------
    while(p) //判断节点指针域是否为空
    {
    q=p->next;
    delete p;
    p=q;
    }
    L->next=NULL;   //将头节点指针域置空
    return OK;
}
//求单链表的长度
int  ListLength_L(LinkList &L)
{
   
    LinkList p;
    int n=0;
    p = L->next;
    //--------
    while (p)
    {
        n++;
        p=p->next;
    }
    return n;
}
//获取单链表中第i个元素的内容
Status GetElem_L(LinkList L,int i,ElemType &e)
{
    LinkList p;
    p=L->next;int j=1;
    while(p&&j<i)
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i)     //判断第j个是否为空。还有j、i是否相等
        return ERROR;
    e=p->data;          //通过引用型参数e，将结果带回
    return OK;
}
//按值查找
int LocateElem_L(LinkList L,int num)
{
    LinkList p;
    p=L->next;int i=1;
    while(p&&p->data.num!=num)
    {
        p=p->next;
        i++;
    }
    if(p)
        return i;
    else
        return 0;
}

