#include <iostream>
using namespace std;
class Box
{
public:
    Box(int ,int ,int); //带参数的构造函数
    int volume();       //一般用法：构造函数名（类型1形参1，形参2，形参3，...）
private:
    //在建立对象时把实参值传递给构造函数的相应的形参，把他们作为数据成员的初始值
    int height;
    int width;
    int length;
};
Box::Box(int h,int w,int l)
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
    class Box box1(12,25,30),box2(10,10,10);
    //前面已知，用户是不能调用构造函数的，所以实参是定义函数时给出的。
    //在建立对象时把实参值传递给构造函数的相应的形参，把他们作为数据成员的初始值
    cout<<box1.volume()<<endl;
    cout<<box2.volume()<<endl;
    return 0;
}

