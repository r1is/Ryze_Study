#include <iostream>
using namespace std;
int GCD(int m,int n)
{
    if(n==0)
        return m;
    else
        return GCD(n,m%n);
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<GCD(a,b)<<endl;
    return 0;
}
