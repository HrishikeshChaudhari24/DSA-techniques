#include<iostream>
using namespace std;
int main(){
    //allocating memeory for the variable
    // int *ptr=new int;
    // cout<<"\nenter the value for the variable:";
    // cin>>*ptr;
    // cout<<"\nvalue of variablles is:"<<*ptr;

    //allocating memeory for the array
    // int n;
    // cout<<"\nenter the size of the array:";
    // cin>>n;
    // int *ptr=new int[n];
    // for(int i=0;i<n;i++){
    //     cin>>ptr[i];
    // }
    // cout<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<ptr[i]<<" ";
    // }

    //allocating memeory for the 2D array
    int n,m;
    cout<<"\nenter the no of rows and columns:";
    cin>>n>>m;
    //creation of 2d array
    int* *arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[m];
    }
    //taking input in the array
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}