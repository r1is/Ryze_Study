#include <iostream>
using namespace std;
class Time
{
public:
    Time()
    {
        hours =0;
        minute = 0;             //使用构造函数实现数据成员的初始化             //构造函数的名字必须与类名一样，不具有任何类型，不具任何返回值
        sec=0;
    }
    void set_time();
    void show_time();
private:
    int hours;
    int minute;
    int sec;
};
void Time::set_time()
{
    cin>>hours;
    cin>>minute;
    cin>>sec;
}
void Time::show_time()
{
    cout<<hours<<":"<<minute<<":"<<sec<<endl;
}
int main()
{
    class Time t1,t2;
    t1.set_time();
    t1.show_time();
//    t2.set_time();
    t2.show_time();
    return 0;
    
}

