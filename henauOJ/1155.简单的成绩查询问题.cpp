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

};
void Student::set_name()
{
    cin>>name;
}
void Student::set_score()
{
    cin>>score;
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
    int Q;
    cin>>Q;
    string find_name[10];
    for(int j=0;j<Q;j++)
        cin>>find_name[j];
    for(int k=0;k<Q;k++)
        for(int h=0;h<n;h++)
            if(stu[h].name==find_name[k])
            {
                cout.setf(ios::fixed);
                cout<<fixed<< setprecision(1)<<stu[h].score<<endl;
            }
    return 0;
    
    
    }


