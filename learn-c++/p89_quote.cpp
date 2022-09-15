#include <iostream>
using namespace std;


//引用作为形式参数
//交换函数

//地址传递
void mySwap01(int* a,int*b);

//引用传递

void Swap03(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void out (int a)
{
    cout << a << endl;
}

//引用作为函数的返回值 

int main(){
    int c =10;
    int &d = c;
    d = 20;
    //cout << a << endl;


    //int &c; 错误，引用必须初始化
    //引用初始化就不能修改

    int a = 10;
    int b = 20;
    Swap03(a,b);
    out(a);
    out(b);
    
}