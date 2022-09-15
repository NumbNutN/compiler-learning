#include <iostream>
using namespace std;



//1.new的基本语法
int* func(){
    //在堆区创建整型数据
    //new 返回一个该数据类型的指针
    int* p = new int(10);
    return p;
}

void test01(){
    int * p = func();
    cout << *p << endl;
}

int main(void){
    test01();
}