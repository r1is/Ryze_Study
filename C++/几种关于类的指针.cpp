
#include <iostream>
#include <string>
using namespace std;
class Time
{
public:
    int hours;
    int minute;
    int sec;
    void set_time();
    void get_time();
};

void Time::get_time()
{
    cout<<hours<<":"<<minute<<":"<<sec<<endl;
}
void Time::set_time()
{
    cin>>hours>>minute>>sec;
}
int main(){
class Time t1;
    t1.set_time();
    t1.get_time();
    cout<<"这是一个指针p:\n";
    int  *p=&t1.hours;
    cout<<*p<<endl;
    void (Time::*p2)();
    p2=&Time::get_time;
    (t1.*p2)();
}
//数据成员指针，指向具体对象中的某个数据成员。
// int *p = &t1.hours  使用数据成员相对应的数据类型进行定义 注意类型和&符号；
//定义指向对象的指针。 class Time *p=&t1;   类指针，使用类名定义。
//class Time *p=&t1;  定义Time指针p，并使p指向t1；
// void(Time::*p)()   定义指向类中公用成员函数的指针p
//p = &Time::get_time;  使指针p指向成员函数get_time
//(t1.p)();             调用对象t1中的成员函数get_time,即t1.get_time();
