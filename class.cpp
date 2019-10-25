#include <iostream>
using namespace std;
class Time{                      //声明Time类
public:                          //以下为公用函数
    Time()                       //定义构造成员函数，函数名字与类名相同
    {
        hours = 0;               //利用构造函数对对象中的数据成员赋值
        minute =0;
        sec= 0;
    }
    void set_time();              //成员函数声明
    void show_time();             //成员函数声明
private:                          //以下为私有数据
    int hours;
    int minute;
    int sec;
};
void Time::set_time()              //定义成员函数，向数据成员赋值
{
    cin>>hours;
    cin>>minute;
    cin>>sec;
}
void Time::show_time()            //定义成员函数，输出数据成员值
{
    cout<<hours<<":"<<minute<<":"<<sec<<endl;
}
int main()

{
    Time t1;                       //建立对象t1，同时调用构造函数t1.Time()
    t1.set_time();                 //对t1的数据成员赋值
    t1.show_time();                //显示t1的数据成员的值
    Time t2;                       //建立对象t2,同时调用构造函数t2.Time()
    t2.show_time();                //显示t2的数据成员值
    return 0;
}


