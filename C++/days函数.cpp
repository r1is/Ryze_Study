#include <iostream>
using namespace std;
struct Data
{
    int year;
    int month;
    int day;
}day_1;
int main(){
    cin>>day_1.year>>day_1.month>>day_1.day;
    int days(int year,int month,int day );
    int aaaaaaa=days(day_1.year, day_1.month, day_1.day);
    cout<<aaaaaaa<<endl;
   
    return 0;
 
}
int days(int year,int month,int day )
{
    
    int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
//    cout<<"请输入年、月、日\n";
//    cin>>day_1.year>>day_1.month>>day_1.day;
    int count =day;
    for(int i=0;i<month;i++)
        count = count+a[i];
    if((month>2)&&((year%4==0&&year%100!=0)||(year%400==0)))
        count+=1;
    return count;
}

