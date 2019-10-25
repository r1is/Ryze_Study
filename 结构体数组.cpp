/*结构体数组
 例：对候选人得票的统计程序。设有3个候选人，最终只有一个人当选为领导。今有10个人参与投票，从键盘先后输入这10个人所投候选人的名字，最后要求输出各候选人的票数结果。
 */
#include <iostream>
using namespace std;
struct Person
{
    char name[20];
    int count;
};
int main()
{
    Person leader[3]={"Li",0,"Zhang",2,"Zhou",4};
    int i,j;
    char leader_name[20];
    for(i=0;i<10;i++)
    {
        cin>>leader_name;
        for(j=0;j<3;j++)
            if(strcmp(leader_name, leader[j].name)==0)
                leader[j].count++;
    }
    cout<<endl;
    for(i=0;i<3;i++)
    {
        cout<<leader[i].name<<":"<<leader[i].count<<endl;
    }
    return 0;
}


