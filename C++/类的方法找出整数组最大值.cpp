#include <iostream>
using namespace std;
class Aarry_Max
{
public:
    void set_value();
    void max_value();
    void show_value();
private:
    int array[10];
    int max;
};
void Aarry_Max::set_value()
{
    for(int i =0;i<10;i++)
        cin>>array[i];
}
void Aarry_Max::max_value()
{
    int i;
    max=array[0];
    for(i=1;i<10;i++)
        if(array[i]>max)
            max=array[i];
}
void Aarry_Max::show_value()
{
    cout<<"max:"<<max<<endl;
}
int main()
{
    
   class Aarry_Max arrmax;
    arrmax.set_value();
    arrmax.max_value();
    arrmax.show_value();
    return 0;
    
}

