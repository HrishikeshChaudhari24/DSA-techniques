#include<iostream>
using namespace std;
void update(int**p2){
    // p2=p2+1;
    // *p2=*p2+1;
    **p2=**p2+1;

}
int main(){
    int i=5;
    int *p=&i;
    int* *p2=&p;
    cout<<"\n before value of i:"<<i<<endl;
    cout<<"\n before value of p:"<<p<<endl;
    cout<<"\n before value of p2:"<<p2<<endl;
    update(p2);
    cout<<"\n after value of i:"<<i<<endl;
    cout<<"\n after value of p:"<<p<<endl;
    cout<<"\n after value of p2:"<<p2<<endl;
    // cout<<"value of i:"<<&i<<endl;
    // cout<<"value of p:"<<p<<endl;
    // cout<<"value of p:"<<*p<<endl;
    // cout<<"address of p:"<<&p<<endl;
    // cout<<"value of p2:"<<*p2<<endl;
    // cout<<"value of p2:"<<**p2<<endl;
    // cout<<"value of p2:"<<p2<<endl;
}