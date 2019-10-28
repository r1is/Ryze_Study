
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
int main()
{
    class Time t1;
    t1.set_time();
    int *p1 = &t1.hours;
    cout<<*p1<<endl;
    t1.get_time();
    Time *p2=&t1;
    p2->get_time();
    void(Time:: *p3)();
    p3=&Time::get_time;
    (t1.*p3)();
    
}

