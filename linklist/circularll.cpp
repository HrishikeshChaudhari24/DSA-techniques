#include<iostream>
using namespace std;
class node{
    public:
    node* next;
    int data;
};
class linkedList{
    public:
        node* head=NULL;
        node* tail=NULL;
        // node* New=new node;
        bool firsttime=true;
        void createnode();
        void display();
};
void linkedList::createnode(){
    node* temp;
    node* New;
    if(firsttime==true){
        New=new node;
        cout<<"\nenter the value";
        cin>>New->data;
        New->next=New;
        head=New;
        tail=New;
        firsttime=false;
    }
    else{
        temp=head;
        while(temp!=tail){
            temp=temp->next;
        }
        temp->next=new node;
        temp=temp->next;
        cout<<"\nenter the data for node:";
        cin>>temp->data;
        temp->next=head;
        tail=temp;
        delete temp;
    }

}
void linkedList::display(){
    node* temp;
    temp=head;
    while(temp->next!=head){
        cout<<temp->data<<"||"<<temp->next<<"|||";
        temp=temp->next;
    }
    cout<<temp->data<<"||"<<temp->next<<"|||";
    cout<<endl;
    cout<<head;
}
int main(){
    linkedList l1;
    int ch=0;
    int dwtc;
    do{
        cout<<"\n1.createnode:\n"<<"2.display linked list:\n";
        cout<<"enter the choice:";
        cin>>ch;
        switch(ch){
            case 1:
                l1.createnode();
                break;
            case 2:
                l1.display();
                break;
            default:
                break;
        }
        cout<<"\ndo you want to continue:";
        cin>>dwtc;
    }while(dwtc==1);
}