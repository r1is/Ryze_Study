#include <iostream>
using namespace std;
class time{
public:
    void set_time();
    void show_time();
private:
    int hours;
    int minute;
    int sec;
};
void time::set_time()
{
    cin>>hours;
    cin>>minute;
    cin>>sec;
}
void time::show_time()
{
    cout<<hours<<":"<<minute<<":"<<sec<<endl;
}
int main()
{
    class time t1;
    t1.set_time();
    t1.show_time();
    class time t2;
    t2.set_time();
    t2.show_time();
    return 0;
}

