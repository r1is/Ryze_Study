#include <iostream>
#include <string>
using namespace std;
struct Student
{
    int num;
    string name;
    char sex;
    float score[3];
}stu={1610101030,"ZhouRui",'B',100,98,89};
int main()
{
    void print(Student *);
    Student *p = &stu;
    print(p);
    return 0;
}
void print(Student *p)
{
    cout<<p->name<<" "<<p->num<<" "<<p->sex<<"\n"
    <<p->score[0]<<" "<<p->score[1]<<" "<<p->score[2]<<endl;
}

