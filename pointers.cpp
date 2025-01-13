#include<iostream>
#include<string.h>
using namespace std;
int main(){
    int a=10;
    int *ptr=&a;
    // ptr=&a;
    // cout<<"address of a:"<<&a<<endl;
    // cout<<"address at ptr:"<<ptr<<endl;
    // cout<<"value of a:"<<*ptr<<endl;
    // (*ptr)++;
    // cout<<"address of a:"<<a<<endl;
    
    int arr[5]={1,2,3,4,5};
    cout<<"\nadddress is:"<<arr<<endl;
    cout<<"\nadddress is:"<<&arr[0]<<endl;
    int *asd=&arr[0];
    // cout<<"value at 2:"<<arr[2]<<endl;
    // cout<<"value at 2:"<<(asd+1)<<endl;
    cout<<"size of array:"<<sizeof(arr)<<endl;
     cout<<"value of pointer:"<<asd<<endl;
    cout<<"size of pointer:"<<sizeof(asd)<<endl;
     cout<<"size of pointer:"<<sizeof(*asd)<<endl;
    for(int i=0;i<5;i++){
        cout<<asd[i]<<" ";
    }
    char temp='z';
    char *mk=&temp;
    cout<<"\nvalue is:"<<mk<<endl; 
    char str[5] = {'a','b','c','d','e'};
    char *bkl=&str[0];
    cout<<"\nvalue is:"<<bkl<<endl;   
}
