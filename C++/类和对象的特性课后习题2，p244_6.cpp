#include <iostream>
using namespace std;
class Cuboid
{
public:
    void set_cuboid();
    void cal_show_cuboid();
private:
    float lenght;
    float width;
    float height;
};
void Cuboid::set_cuboid()
{
    cin>>lenght;
    cin>>width;
    cin>>height;
}
void Cuboid::cal_show_cuboid()
{
    cout<<lenght*width*height<<endl;
}
int main()
{
    class Cuboid c1,c2,c3;
    c1.set_cuboid();
    c2.set_cuboid();
    c3.set_cuboid();
    cout<<"------------------\n";
    c1.cal_show_cuboid();
    c2.cal_show_cuboid();
    c3.cal_show_cuboid();
    cout<<"------------------\n";
    return 0;
    
}



