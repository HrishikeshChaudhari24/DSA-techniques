#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node *left=NULL;
        node *right=NULL;
};
class trees{
    public:
    node* root=NULL;
    node* head;
    
    void insert();
    void inorder(node* temp);
    void postorder(node* temp);
    void preorder(node* temp);
};
void trees::insert(){
    int value;
    node* New=NULL;
    
    node *temp;
    temp=root;
    cout<<"\nenter the value for tree:";
    cin>>value;
    // cout<<"\nvalue of root1:"<<root->data;
    New=new node;
    New->data=value;
    
    if(root==NULL){
        root=New;
        // delete New;
        return;
    }
    // cout<<"\nvalue of root3:"<<root->data;
    while(New!=NULL){
        // cout<<"\nvalue of root4:"<<root->data;
        char choice;
        cout<<"\nWhere to insert left/right of "<<temp->data<<":";
        cin>>choice;
        if(choice=='r' || choice=='R'){
            if(temp->right==NULL){

                temp->right=New;
                New=NULL;
                break;
            }
            else{
                temp=temp->right;
            }
        }
        else{
            if(temp->left==NULL){

                temp->left=New;
                New=NULL;
                break;
            }
            else{
                temp=temp->left;
                
            }
        }
    }
    delete New;
}
void trees::inorder(node* temp){
    if(temp==NULL){
        return;
    }
    inorder(temp->left);
    cout<<temp->data<<" ";
    inorder(temp->right);
}
void trees::postorder(node* temp){
    if(temp==NULL){
        return;
    }
    postorder(temp->left);
    postorder(temp->right);
    cout<<temp->data<<" ";
}
void trees::preorder(node* temp){
    if(temp==NULL){
        return;
    }
    cout<<temp->data<<" ";
    preorder(temp->left);
    preorder(temp->right);
}
int main(){
    trees b1;
    node* r1=b1.root;
    int ch,h;
    int option;
    do
    {
        cout<<"\n*********MENU*******";
        cout<<"\n1.creation: \n2.display: \n"<<endl;
        cin>>option;
        switch (option)
        {
            case 1:
                b1.insert();
                // r1=b1.root;
                break;
            case 2:
                // cout<<"\naddress of root is:"<<b1.root<<endl;
                r1=b1.root;
                b1.inorder(r1);
                cout<<endl;
                b1.postorder(r1);
                cout<<endl;
                b1.preorder(r1);
                cout<<endl;
                break;
            
            default:
                break;
        }
        cout<<"\ndo you want to continue??";
        cin>>ch;
    } while (ch==1);
}