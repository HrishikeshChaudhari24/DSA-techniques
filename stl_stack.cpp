#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<string>s;
    cout<<"\ninserting elements in stack:";
    for(int i=0;i<3;i++){
        string ele;
        cin>>ele;
        s.push(ele);
    }
    cout<<"\nprinting the elements of the stack:";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    //direct access to element is not possible
    //erase function works same as that of deque
}