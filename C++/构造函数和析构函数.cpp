#include <iostream>
#include <string>
using namespace std;
class Student
{
public:
    Student(int n,string nam,char s)
    {
        num = n;
        name = nam;
        sex = s;
        cout<<"Constructor."<<endl;
    }
    ~Student()
    {
        cout<<"Constructor called."<<endl;     //析构函数
    }//析构函数并不是删除对象，而是在撤销对象占用的内存前完成yx一些清理工作
    //析构函数不返回任何值、没有函数类型、也没有参数
    //一个类可以有多个构造函数，但是只能有一个析构函数
    void display();
private:
    int num;
    string name;
    char sex;
};
void Student::display()
{
    cout<<"num:"<<num<<endl;
    cout<<"name:"<<name<<endl;
    cout<<"sex:"<<sex<<endl<<endl;
}
int main()
{
    class Student stu1(1610101030,"ZhouRui",'B');
    stu1.display();
    class Student stu2(1610101022,"WuMing",'G');
    stu2.display();
    return 0;
}

