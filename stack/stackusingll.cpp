#include<iostream>
using namespace std;
class node{
    public:
        node* next=NULL;
        int data;
};
class stackll{
    public:
        node* head;
        int top=-1;
        bool firstTime=true;
        void insert();
        void pop();
        void display();
};
void stackll::insert(){
    node *New;
    if(firstTime==true){
        New=new node;
        New->next=NULL;

        top++;
        cout<<"\nenter the value:";
        cin>>New->data;
        head=New;
        firstTime=false;
        free(New);
    }
    else{
        top++;
        New=new node;
        New->next=head;
        cout<<"\nenter the value:";
        cin>>New->data;
        head=New;
        delete New;
    }
}
void stackll::pop(){
    if(top==-1){
        cout<<"\nthere is nothing to pop:";
        return;
    }
    top--;
    node* temp;
    temp=head->next;
    free(head);
    head=temp;
}
void stackll::display(){
    if(top==-1){
        cout<<"\nthere is nothing to display:";
        return;
    }
    node* temp;
    temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<"||"<<temp->next<<"|||";
        temp=temp->next;
    }
    cout<<temp->data<<"||"<<temp->next<<"|||";
}
int main(){
    stackll l1;
    int ch=0;
    int dwtc;
    do{
        cout<<"\n1.insert:\n"<<"2.display stack:\n"<<"3.pop:\n";
        cout<<"enter the choice:";
        cin>>ch;
        switch(ch){
            case 1:
                l1.insert();
                break;
            case 2:
                l1.display();
                break;
            case 3:
                l1.pop();
                break;
            default:
                break;
        }
        cout<<"\ndo you want to continue:";
        cin>>dwtc;
    }while(dwtc==1);
}