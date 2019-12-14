# 1065: 回文数一
题目描述
求11到n之间（包括n），既是素数又是回文数的整数有多少个。
输入
一个大于11小于1000的整数n。
```
#include<iostream>
#include<cstdio>
using namespace std;
bool isPalindrome(int x)
{
    
    if (x < 0 || (x % 10 == 0 && x != 0))
        return false;
    int revertedNumber = 0;
    while (x > revertedNumber) {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }
    return x == revertedNumber || x == revertedNumber / 10;
}
void show_count(int n)
{
    bool prime[1000];
    for (int i = 0; i < 1000; ++i)
    {
        prime[i]=0;
    }
    prime[0]=1;
    prime[1]=1;
    for(int i=2;i<1000;i++){
        if(prime[i]==0){
            for(int j=i*2;j<1000;j+=i)
                prime[j]=1;
        }
    }
    int num;
    num=0;
    for(int i=11;i<=n;i++)
    {
        if(isPalindrome(i)&&(prime[i]==0))
            num++;
    }
    cout<<num<<endl;
}
int main()
{
    int n;
    cin>>n;
    show_count(n);
    return 0;
}

```
