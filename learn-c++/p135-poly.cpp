//静态多态：编译阶段确定函数地址
//动态多态：运行阶段确定函数地址

#include <iostream>
using namespace std;

//动物类
class Animal
{
    public:
    //虚函数
        virtual void speak()
        {
            cout << "动物在说话" << endl;
        }
};

//猫类
class Cat: public Animal
{
    public:
        void speak()
        {
            cout << "小猫在说话" << endl;
        }
};

//如果想执行让猫说话，那么这个函数地址就不能提前绑定
void doSpeak(Animal &animal)
{
    animal.speak();
    //c++允许父子类间的类型转换
}

void test01(){
    Cat cat;
    doSpeak(cat);
}

int main()
{
    test01();
}