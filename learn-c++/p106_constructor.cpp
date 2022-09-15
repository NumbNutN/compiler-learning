//构造函数  类名(){}

//析构函数  ~类名(){}

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

        ~Person()
        {
            cout << "Person 析构函数调用" << endl;
        }
};

//构造函数的分类及调用

//有参构造/无参构造
//普通构造函数/拷贝构造函数
class Student
{           
    public:
        int m_age;
        Student()
        {
            cout << "Student的无参构造函数调用" << endl;
        }

        Student(int age)
        {
            cout << "Student的有参构造函数调用" << endl;
            m_age =age;
        }

        ~Student()
        {
            cout <<"Student析构函数调用" << endl;
        }

        //拷贝构造函数
        Student(const Student &p)
        {
            //将传入的人身上的所有属性拷贝到当前对象身上
            cout << "Student的拷贝构造函数调用" << endl;
            m_age = p.m_age;
        }
        
};

void test01()
{
    //1.括号法
    Student p;  //默认构造函数的调用
    Student p2(10);
    Student p3(p2);

    //打印年龄
    cout << "p2的年龄：" <<p2.m_age << endl;
    cout << "p3的年龄：" <<p3.m_age << endl;

    //2.显示法

    //3.隐式转换法
}
int main(){
    //Person p1;

    //函数的调用
    test01();

}


