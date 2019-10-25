//指向结构体变量的指针
//指向结构体变量的指针的定义和使用
#include <string>
#include <iostream>
using namespace std;
int main()
{
    struct Student
    {
        int num;
        string name;
        char sex;
        float score;
    };
    Student stu;
    Student *p =&stu;
    stu.num=10301;
    stu.name="Wang Ming";
    stu.sex = 'F';
    stu.score = 89.2;
    cout<<stu.num<<" "<<stu.name<<" "<<stu.sex<<" "<<stu.score<<endl<<endl;
    cout<<(*p).num<<" "<<(*p).name<<" "<<(*p).sex<<" "<<(*p).score<<endl;
    return 0;
}


