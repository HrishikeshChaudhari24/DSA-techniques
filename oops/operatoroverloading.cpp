#include<iostream>
using namespace std;
class opoverload{
    public:
        int a=10;
        void operator+ (opoverload &o3 ){
            int value1=this->a;
            int value2=o3.a;
            cout<<"Subtraction of two object is:"<<value1-value2;
        }
};
int main(){
    opoverload o1;
    opoverload o2;
    o2.a=5;
    o1+o2;
}