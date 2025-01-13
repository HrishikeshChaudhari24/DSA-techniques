#include<iostream>
using namespace std;

class A{
    public:
        void print(){
            cout<<"\nhi i am A";
        }
};
class B:public A{
    public:
        void print(){
            cout<<"\nhi i am B";
        }
};
int main(){
    B b1;
    b1.print();
    b1.A::print();
}