#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int>l;
    cout<<"\ninserting elements in list:";
    for(int i=0;i<5;i++){
        int ele;
        cin>>ele;
        l.push_back(ele);
    }
    //direct access to element is not possible
    //erase function works same as that of deque
}