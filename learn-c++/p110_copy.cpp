#include <iostream>
using namespace std;

class Person
{
    //构造函数可以发生重载
    public:
        Person()
        {
            cout << "Person 构造函数的调用" << endl;
        };

        Person(int age,int height)
        {
            m_Age = age;
            m_Height = new int(height);
        }

        //自己实现拷贝构造函数
        Person(const Person &p)
        {
            cout << "Person的拷贝构造函数调用";
            m_Age = p.m_Age;
            m_Height = new int(*p.m_Height);
        }


        ~Person()
        {
            //析构代码的用途：将堆区开辟的数据做释放操作
            if(m_Height != NULL)
            {
                delete m_Height;
                m_Height = NULL;
            }
            cout << "Person 析构函数调用" << endl;
        }

        void func()
        {
            cout << "年龄为：" << m_Age << endl;
            cout << "身高为：" << m_Height << endl;
        }

        int m_Age;
        int* m_Height;
};

int main(){
    Person p1(18,180);
    Person p2(p1);

    p1.func();
    p2.func();
    //编译器为调用默认拷贝构造函数
    //浅拷贝带来的问题，堆区的重复释放

    //如果有在堆区开辟内存空间，一定要自己提供拷贝构造函数



}