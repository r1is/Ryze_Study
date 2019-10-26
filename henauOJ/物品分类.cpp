#include <iostream>
const int N=100;
using namespace std;
class goods
{
public:
    void set_goods()
    {
        cin>>name>>kind;
    }
    string name;
    string kind;
};
int main()
{
    int n;
    class goods good[N];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        good[i].set_goods();
    }
    //Keyboard，Mouse，Single_reflex，Earphone，Player
    int Count_Keyboard=0;
    int Count_Mouse=0;
    int Count_Single_reflex=0;
    int Count_Earphone=0;
    int Count_Player=0;
    //Keyboard: d1
    //Mouse: d1
    //Single_reflex: d1
    //Earphone: d1
    //Player: d1
    for(int j=0;j<n;j++)
    {
        if(good[j].kind=="Keyboard")
            Count_Keyboard++;
        else if (good[j].kind=="Mouse")
            Count_Mouse++;
        else if (good[j].kind=="Single_reflex")
            Count_Single_reflex++;
        else if (good[j].kind=="Earphone")
            Count_Earphone++;
        else if(good[j].kind=="Player")
            Count_Player++;
    }
     cout<<"Keyboard: "<<Count_Keyboard<<endl;
     cout<<"Mouse: "<<Count_Mouse<<endl;
     cout<<"Single_reflex: "<<Count_Single_reflex<<endl;
     cout<<"Earphone: "<<Count_Earphone<<endl;
     cout<<"Player: "<<Count_Player<<endl;
    return 0;
    
}

