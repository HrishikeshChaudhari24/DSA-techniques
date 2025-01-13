#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<string>s;
    cout<<"\ninserting elements in queue:";
    for(int i=0;i<3;i++){
        string ele;
        cin>>ele;
        s.push(ele);
    }
    cout<<"\nprinting the elements of the stack:";
    while(!s.empty()){
        cout<<s.front()<<" ";
        s.pop();
    }
    //direct access to element is not possible
    //erase function works same as that of deque
}