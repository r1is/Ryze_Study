#include <iostream>
using namespace std;
struct Data
{
    int year;
    int month;
    int day;
}day_1;
int main(){
   
    int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    cout<<"请输入年、月、日\n";
    cin>>day_1.year>>day_1.month>>day_1.day;
    int count =day_1.day;
    for(int i=0;i<day_1.month;i++)
        count = count+a[i];
    if((day_1.month>2)&&((day_1.year%4==0&&day_1.year%100!=0)||(day_1.year%400==0)))
        count+=1;
    cout<<day_1.year<<"年"<<day_1.month<<"月"<<day_1.day<<"日\n";
    cout<<"是"<<day_1.year<<"年第"<<count<<"天"<<endl;
    return 0;
 
}

