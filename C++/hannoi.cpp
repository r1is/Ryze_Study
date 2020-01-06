#include <iostream>
using namespace std;
void move(char A,char B)
{
  cout<<A<<"-->"<<B<<endl;
}
void hannoi(int n,char A,char B,char C)
{
  if(n==1)
  {move(A,C);}
  else
  {
    {
      hannoi(n-1,A,C,B);
      move(A,C);
      hannoi(n-1,B,A,C);
    }
  }
  
}
int move_s(int n)
{
  if(n==1)
  return 1;
  else
    return 2*move_s(n-1)+1;
  
  
}
int main()
{
  int n;
  cin>>n;
  hannoi(n,'A','B','C');
  cout<<"=================\n";
  printf("一共移动%d次\n",move_s(n));
 cout<<"=================\n"; 
  return 0;
}