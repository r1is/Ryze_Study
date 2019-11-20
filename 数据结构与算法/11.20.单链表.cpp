#include <iostream>
using namespace std;
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
//在链表L中插入新的元素
//在第i个元素前插入新元素e
Status ListInsert_L(LinkList &L,int i,ElemType e)
{
    LinkList p;
    p=L; int j=0;
    while(p&&j<i-1)  //寻找第i-1个结点
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i-1)           //i大于表长加1，或小于1。返回错误
        return ERROR;
     LinkList s = new Lnode;        //创建一个新的结点s
    s->data = e;                    //将e的值赋给新结点的data域
    s->next = p->next;              //新结点的指针域指向之前第i个结点
    p->next = s;                    //之前第i-1个结点指向新结点s
    return OK;
}
//删除第i个结点
Status ListDelete_L(LinkList &L,int i,ElemType &e)
{
    LinkList p;
    p=L;int j=0;
    while((p->next)&&(j<i-1))
    {
        p=p->next;
        ++j;
    }
    if(!(p->next)||j>i-1)
        return ERROR;
    LinkList q =p->next;
    p->next = p->next->next;
    q->data =e;
    delete q;
    return OK;
    
}
//头插法建立单链表
void CreateList_H(LinkList &L,int n)
{
    L = new Lnode;
    L->next = NULL;      //建立一个带带结点的单链表
    for(int i=n;i>0;i--)
    {
        LinkList p = new Lnode;   //生成新的结点
        cin>>(p->data.name);
        cin>>(p->data.num);
        cin>>(p->data.score);
        p->next = L->next;              //插入到表头
        L->next = p;
    }
}//CreateList_H
//尾插法建立单链表
void CreateList_R(LinkList &L,int n)
{
    L= new Lnode;                     //建立一个头节点
    L->next = NULL;
    LinkList r;                      //建立一个尾指针，指向单链表的最后一个元素
    r = L;                           //尾指针指向头节点
    for(int i=0;i<0;++i)
    {
        LinkList p =new Lnode;
        //输入数据
        //--------------------
        cin>>(p->data.name);
        cin>>(p->data.num);
        cin>>(p->data.score);
        //--------------------
        p->next = NULL;
        r->next = p;               //将新建立的结点接入表中，也就是尾指向指向新的结点
        r=p;                       //完成接入后，更新尾指针
    }
}//CreateList_R


