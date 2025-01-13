#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int>st;
    st.push(20);
    st.push(100);
    cout<<st.empty()<<endl;
    cout<<st.top()<<endl;
    cout<<st.size()<<endl;
}