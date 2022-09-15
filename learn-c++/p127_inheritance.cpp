#include <iostream>
using namespace std;

class PageBase{
    public:
        void header()
        {
            cout << "首页" << endl;
        }
};

class Java: public PageBase{
    public:
        void content()
        {
            cout << "java页面" << endl;
        }
};

int main(){
    Java java;
    java.header();
    java.content();
    //派生类继承了父类的方法
}