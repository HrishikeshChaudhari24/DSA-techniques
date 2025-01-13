#include<iostream>
using namespace std;
int main(){
    // int arr[6]={1,2,3,4,5,6};
    // int *ptr=arr;
    
    // cout<<*ptr<<endl;
    // cout<<*(ptr+1)<<endl;
    // cout<<(ptr+2)<<endl;
    // cout<<&arr[2]<<endl;
    // cout<<arr+2<<endl;
    // cout<<2[arr]<<endl;
    // arr=arr+2;
    //pass by reference
    int a=10;
    int &b=a;
    cout<<a<<"|| "<<b++<<"| "<<a;
}
