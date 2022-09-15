#define PI 3.1415
#include <iostream>
using namespace std;

//class 代表设计一个类
class Circle{

    public:

        //属性
        //半径
        int m_r;

        //获取圆的周长
        double calculateZC(){
            return 2*PI*m_r;
        }
};




int main(){
    //通过原类创建一个具体的对象
    Circle cl;
    cl.m_r = 10;

    cout << "圆的周长为：" << cl.calculateZC() << endl;
}

//class的默认权限是私有
//struct的默认权限是公共

//方法中未声明直接用的变量是成员属性