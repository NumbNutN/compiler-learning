#include <iostream>
using namespace std;

class Base{
    public:
        void func(){
            cout << "Hello Base" << endl;
        }
};

int main(){
    Base* p = new Base();
    p->func();
    delete(p);
}