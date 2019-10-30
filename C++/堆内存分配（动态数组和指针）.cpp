
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int arraysize;          //元素个数
    int *array;
    cout<<"请输入元素的个数\n";
    cin>>arraysize;
    cout<<"int的大小为："<<sizeof(int)<<endl;
    array = (int *)malloc(arraysize *sizeof(int));//堆内存分配
// 上述写法不安全，如果堆内空间不够，这时对该指针的访问都是破坏性的
//if(arry=(int *)malloc(arraysize*sizeof(int))==NULL)
//{cout<<"申请内存失败！\n";
//exit(1);
//}
    for(int i=0;i<arraysize;i++)
        array[i]=i*3;
    for(int i=0;i<arraysize;i++)
        cout<<array[i]<<" ";
    cout<<endl;
    free(array);
    return 0;
    
}
// malloc(n* sizeof(....))   分配内存大小
//free()                    释放内存
//free()的原型为：void(void *)
//堆内存的分配（动态数组和指针）

