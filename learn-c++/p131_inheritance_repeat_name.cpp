#include <iostream>
using namespace std;

class Base{
    public:
        Base(){
            m_A = 100;
        }
        int m_A;

        void func(int a){
            cout << "base的方法实现" << a <<endl;
        }
};

class Son: public Base{
    public:
        Son(){
            m_A = 200;
        }
        int m_A;
};

int main(void){
    Son a;
    cout << "M_A:" << a.m_A << endl;
    //子类对方法进行重写
    //通过子类成员访问父类同名属性需要访问作用域
    cout << "Base的M_A:" << a.Base::m_A << endl;

    //同名子类【方法】也直接调用子类方法

    //如果子类中出现和父类同名的成员函数，子类会隐藏父类的同名成员函数
}