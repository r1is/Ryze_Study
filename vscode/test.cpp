#include <iostream>
using namespace std;
class Circle
{
    public:
    Circle(int r):radius(r){};
    int radius;
};
class Table
{
    public:
    Table(int h):height(h){};
    int height;
};
class RoundTable:public Circle,public Table
{
    public:
    //RoundTable(int r,int,c):color(c){};
    RoundTable(int r,int h):circle(r),T
    int color;
    void show_info();
};
void RoundTable::show_info()
{
    cout<< "radius = "<< radius<<endl
    <<"height = "<<height<<endl
    <<"color = "<<color<<endl;
}
int main()
{
    RoundTable r1;
}