#include<iostream>
using namespace std;
void value(int *ptr){
    ptr=ptr+1;
    cout<<"\n value of pointer inside the function is:"<<*ptr;
}
int main(){
    // working of pointer on integer array
    // int arr[5]={1,2,3,4,5};
    
    // int *ptr=&arr[0];
    // cout<<"value:"<<arr<<endl;
    // cout<<"value:"<<*(arr+1)<<endl;
    // cout<<"value:"<<&arr[1]<<endl;
    // cout<<"value of ptr:"<<ptr;
    // //in backend working of arr is pointer. arr have starting address and based on that everytime the value at particular location is 
    // //computed which is given as arr[1 or 2 and so on]
    // cout<<"\nvalue at location 2:"<<ptr[2];

    // working on character array
    // char str[]="abcde";
    // char str2[4]={'a','b','c','d'};
    // cout<<"value of str2:"<<str2<<endl;
    // char *ptr=&str[0];
    // cout<<"value:"<<&str<<endl;
    // cout<<"all started here:"<<endl;
    // for(int i=0;str2[i]!='\0';i++){

    //    cout<<"value:"<<i<<":"<<&str2+i<<endl;
    // }
    // cout<<"all ended here:"<<endl;
    // cout<<"value:"<<(&ptr[0])<<endl;
    // cout<<"value:"<<&str[2]<<endl;

    // working wiht the function
    int val=10;
    int *ptr=&val;
    cout<<"\n value of val:"<<val<<endl;
    cout<<"\n value of pointer ouside the function:"<<ptr<<endl;
    value(ptr);
    cout<<"\n value of pointer after ouside the function:"<<ptr<<endl;
    cout<<"\n value of val:"<<val<<endl;
}