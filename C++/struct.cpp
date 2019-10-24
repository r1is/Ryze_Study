#include <iostream>
using namespace std;
struct Date
{
    int month;
    int day;
    int year;
};
struct Student
{
    int num;
    char name[20];
    char sex;
    Date birthday;
    float score;
}student1,student2={10002,"wangming",'g',10,10,1997,90.1};
int main()
{
    student1=student2;
    cout<<student1.num<<endl;
     cout<<student1.name<<endl;
     cout<<student1.birthday.year<<'/';
    cout<<student1.birthday.month<<'/';
     cout<<student1.birthday.day<<endl;
    cout<<student1.score<<endl;
    return 0;
    
}

