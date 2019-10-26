#include <iostream>
using namespace std;
class Box
{
public:
    Box(int h=10,int w=10,int l=10);//在声明构造函数时指定默认参数
    int volume();               //声明成员函数volume
private:
    int height;
    int width;
    int length;
};
Box::Box(int h,int w,int l )     //在定h构造函数时可以不指定默认参数
{
    height = h;
    width = w;
    length = l;
}
int Box::volume()
{
    return height*width*length;
}
int main()
{
    class Box box1,box2(10,1,99);
    cout<<box1.volume()<<endl;
    cout<<box2.volume()<<endl;
    return 0;
}

