#const指针
##（1）指向常量的指针
---
在指针定义语句的类型前加const，表示指向的对象是常量。例如：
```
const int a = 78;
const int b =28;
int c = 0;
const int *p = &a;  //指针类型前脚const
*p = 58;	    //error：不能修改指针指向的常量
pi = &b;	//OK 指针值可以修改
```
##(2)指针常量
---
在定义指针语句的指针名前面加const,表示指针本身就是常量 
```
char* const pc = "asdf";//表示定义一个指针常量
```
##(3)指向常量的指针常量
---
可以定义一个指向常量的指针常量，他必须在定义时进行初始化。例如：
```
const int ci =7;
in ai;
const int *const cpc = &ci;//指向常量的指针常量
const int *const cpi = &ai;//ok
cpi = &ai;//error：指针值不能修改
*cpi = 39;//error 不能修改所指向的对象
ai =39;  //ok
```
