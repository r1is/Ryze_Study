#include <iostream>
#include <string>
#include <iomanip>
const int N=100;
using namespace std;
class Student
{
public:
    string name;
    double score;
    void set_name();
    void set_score();
    void show_Student();
};
void Student::set_name()
{
    cin>>name;
}
void Student::set_score()
{
    cin>>score;
}
void   Student::show_Student()
{  cout.setf(ios::fixed);
   // cout<<fixed<< setprecision(1)<<stu[h].score<<endl;
    cout<<name<<" "<<fixed<< setprecision(1)<<score<<endl;
}
int main()
{
    int n;
    class Student stu[N];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        stu[i].set_name();
        stu[i].set_score();
    }
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(stu[i].score<stu[j].score)
            {
                double temp_1;
                temp_1=stu[i].score;
                stu[i].score=stu[j].score;
                stu[j].score=temp_1;
                string temp_2;
                temp_2 = stu[i].name;
                stu[i].name=stu[j].name;
                stu[j].name=temp_2;
            }
    for(int i=0;i<n;i++)
        stu[i].show_Student();
    return 0;
            
}

