#include <iostream>
using namespace std;
#define N 100
class uses
{
public:
    string Username;
    string Userpwd;
public:
    void set_name()
    {
        cin>>Username;
    }
    void set_pwd()
    {
        cin>>Username;
    }

};
class uses user[N];
enum op{login,signup,forgetpwd};
void Opration(class uses user ,int Op,string user_name,string user_pwd)
{
    switch(Op){
        case 0:{
            if(user_name==user.Username)
            cout<<"login successfully"<<endl;
        }
        
    }

}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        user[i].set_name();
        user[i].set_pwd();
    }
    


}

