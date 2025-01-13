#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int> a;
    deque<int>::iterator s, e;
    cout<<"pushing the elements in deque:"<<endl;
    for(int i=0;i<5;i++){
        int element;
        cin>>element;
        a.push_back(element);
        // cout<<"max_size of deque:"<<a.max_size()<<endl;
        cout<<"size of deque:"<<a.size()<<endl;
    }
    a.push_front(100);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    a.pop_back();
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    a.pop_front();
    //displaying the element of the deque
    cout<<"\nbefore erase:"<<endl;
    for(int i:a){
        cout<<i<<" ";
    }
    //erase function of the deque
    s=a.begin();
    e=a.end()-1;
    a.erase(s,e);
    cout<<"\nafter erase:"<<endl;
    for(int i:a){
        cout<<i<<" ";
    }
}