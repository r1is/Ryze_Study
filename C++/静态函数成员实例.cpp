#include <iostream>
using namespace std;
class Student
{
public:
    Student(int n,int a,float s):num(n),age(a),socre(s){}       //定义构造函数
    void total();                                               //声明成员函数
    static float average();                                     //声明静态成员函数
private:
    int num;
    int age;
    float socre;
    static float sum;                                           //静态数据成员sum总分
    static int count;                                           //静态数据成员count计数
};
void Student::total()                                           //定义非静态成员函数
{
    sum+=socre;                                                 //累计加总分
    count++;                                                    //累计已统计的人数
}
float Student::average()
{
    return (sum/count);
}
float Student::sum=0;
int Student::count=0;                                           //对静态数据成员初始化
int main()
{
    Student stud[3]={                                           //定义对象并初始化
        Student(1001,18,70),
        Student(1002, 19, 78),
        Student(1005, 20, 98)
    };
    int n;
    cout<<"please input the number of students:";
    cin>>n;
    for(int i=0;i<n;i++)
        stud[i].total();
    cout<<"the average score of "<<n<<"student is "<<Student::average()<<endl;
                                                            //调用静态成员函数
    return 0;
}

