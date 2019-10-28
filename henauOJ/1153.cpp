/*题目描述
//依次给你n个学生的姓名、学号，然后Q次询问，对于每一次询问你会得到一个学号，请你输出该学号对应的姓名。 
//输入
第一行输入一个整数n（1<=n<=100），然后n行，每行输入一个长度不超过15的字符串s，表示姓名和一个10位整数，表示学号。（学号保证没有前导零且每个学号都不相同）
再输入一个整数Q（0<=Q<=10），紧接着Q次询问，每次询问输入一个10位整数，表示询问的学号。（保证询问的学号存在）
输出
对于每一次询问输出与学号对应的姓名。*/
#include <iostream>
#include <string>
const int N=100;
using namespace std;
class Student
{
private:
    long long num;
    string name;
public:
    void set_info()
    {
        cin>>name;
        cin>>num;
    }
    void show_info(long long n)
    {
        if(n==num)
            cout<<name<<endl;
    }
};
int main()
{
    class Student stu[N];
    int  n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        stu[i].set_info();
    }
    int Q;
    cin>>Q;
    long long num_info[Q];
    for(int i=0;i<Q;i++)
        cin>>num_info[i];
    for(int i=0;i<Q;i++)
        for(int j=0;j<n;j++)
            stu[j].show_info(num_info[i]);
    return 0;
        
}



