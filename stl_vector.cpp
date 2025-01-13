#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>a;
    cout<<"inserting elements in vector"<<endl;
    for(int i=0;i<5;i++){
        int ele;
        cin>>ele;
        a.push_back(ele);
        cout<<"capacity of vector:"<<a.capacity()<<endl;
        cout<<"size of vector:"<<a.size()<<endl;
    }
    //cpotying element of one vector to another
    vector<int>b(a);
    cout<<"\ndisplaying elements of a and b:"<<endl;
    //displaying elements
    for(int i=0;i<b.size();i++){
        cout<<b[i]<<" ";
    }

    //declaring the vector with its size and initializing it with particular value
    vector<int>c(5,1);
    cout<<"\ndisplaying elements of c:"<<endl;
    for(int i=0;i<b.size();i++){
        cout<<c[i]<<" ";
    }
}