#include <iostream>
#include "Dater.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    int y=0;
    int m=0;
    int d=0;
    cout<<"请输入具体的年月日（eg:2000 10 10）:"<<endl;
    cin>>y>>m>>d;
    CDater dater(y,m,d);
    cout<<"总的天数为："<<dater.TotalDays()<<endl;
    return 0;
}
