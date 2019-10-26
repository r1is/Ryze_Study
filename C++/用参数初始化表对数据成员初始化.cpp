#include <iostream>
using namespace std;
class Box
{
public:
    Box();                  //声明一个无参数的构造函数Box
    Box(int h,int w,int l):height(h),width(w),length(l){}
                            //定义一个有参数的构造函数，用参数的初始化表对数据成员进行初始化
    int volume();               //声明成员函数volume
private:
    int height;
    int width;
    int length;
};
Box::Box()                  //在类外定义无参数构造函数Box
{
    height = 10;
    width = 10;
    length = 10;
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

