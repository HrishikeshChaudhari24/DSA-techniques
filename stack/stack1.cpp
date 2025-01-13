#include<iostream>
using namespace std;
class Stack1{
    public:
        int *arr;
        int top;
        int size;

        Stack1(int size){
            this->size=size;
            top=-1;
            arr=new int[size];
        }
        void push(int element);
        void pop();
        int peek();
        bool isEmpty();
};
void Stack1::push(int element){
    if(top==size-1){
        cout<<"\nStack is full!!";
        return;
    }
    top++;
    arr[top]=element;
    cout<<"\ntop:"<<top;
}
void Stack1::pop(){
    if(top==-1){
        cout<<"\nStack is completely empty!!";
        return;
    }
    top--;
}
int Stack1::peek(){
    if(top==-1){
        cout<<"\nThere is no top of Stack!!";
        return -1;
    }
    cout<<"\nTop element is:"<<arr[top];
}
bool Stack1::isEmpty(){
    if(top==-1){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    Stack1 st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.peek();
    st.pop(); 
    st.peek();
    st.pop(); 
    st.peek();
    st.pop(); 
    st.peek();
    st.pop(); 
    st.peek();
        st.pop(); 
    st.peek();
}