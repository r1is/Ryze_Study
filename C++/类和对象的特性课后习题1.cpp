//
//#include <iostream>
//using namespace std;
//class Time
//{
//public:
//    void set_time();
//    void show_time();
//
//    int hours;
//    int minute;
//    int sec;
//};
//class Time t;
//int main(){
//
//    t.set_time();
//    t.show_time();
//    return 0;
//}
//void Time::set_time()
//{
//    cin>>hours;
//    cin>>minute;
//    cin>>sec;
//}
//void Time::show_time()
//{
//    cout<<hours<<":"<<minute<<":"<<sec<<endl;
//}
//#include <iostream>
//using namespace std;
//class time
//{
//private:
//    int hours;
//    int minute;
//    int sec;
//public:
//    void set_time();
//    void show_time();           //在类体内声明成员函数
//};
//int main()
//{
//    class time t1;
//    t1.set_time();
//    t1.show_time();
//    return 0;
//}
//void time::set_time()
//{
//    cin>>hours;
//    cin>>minute;
//    cin>>sec;                    //在类外定义成员函数
//}
//void time::show_time()
//{
//    cout<<hours<<":"<<minute<<":"<<sec<<endl;
//}
//
//
#include <iostream>
using namespace std;
class time
{
private:
    int hours;
    int minute;
    int sec;
public:
    void set_time()
    {
        cin>>hours;
        cin>>minute;            //在类体内定义成员函数
        cin>>sec;
    }
    void show_time()
    {
       cout<<hours<<":"<<minute<<":"<<sec<<endl;
    }
};
int main()
{
    class time t1;
    t1.set_time();
    t1.show_time();
    return 0;
}
//2019-10-26 PM 2:01 类和对象的特性课后习题

