#include<iostream>
#include<array>
using namespace std;
int main(){
    array<int,6>a={1,2,3,4,5,6};
    cout<<"elements in array are:";
    for(int i=0;i<6;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    //different stl array operations
    cout<<"array is empt0y or not:"<<a.empty()<<endl;
    cout<<"front element of the arrya:"<<a.front()<<endl;
    cout<<"last element of the arrya:"<<a.back()<<endl;
    cout<<"size of the arrya:"<<a.size()<<endl;


}