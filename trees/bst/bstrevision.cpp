#include<iostream>
using namespace std;
class node{
    public:
        int data=0;
        node* left=NULL;
        node* right=NULL;

        node(int data){
            this->data=data;
            left=right=NULL;
        }
};

class BST{
    public:
        node* root=NULL;
        void take_input();
        node* buildTree(node* root,int data);
        void inorder(node* root);
        node* min(node* root);
        node* deleteFromBst(node* temp,int val);    
};
node* BST::buildTree(node* root,int data){
    if(root==NULL){
        root=new node(data);
        return root;
    }
    if(data<root->data){
        root->left=buildTree(root->left,data);
    }
    else if(data>root->data){
        root->right=buildTree(root->right,data);
    }
    return root;
}
void BST::take_input(){
    int data=0;
    cout<<"Enter the data for the node:";
    cin>>data;
    while(data!=-1){
        root=buildTree(root,data);
        cin>>data;
    }
}
void BST::inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
node* BST::min(node* temp){
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
node* BST::deleteFromBst(node* temp,int val){
    if(temp==NULL){
        return temp;
    }
    if(temp->data==val){
        if(temp->left==NULL && temp->right==NULL){
             delete temp;
            return NULL;
        }
        if(temp->left==NULL && temp->right!=NULL){
            node* dummy=temp->right;
            delete temp;
            return dummy;
        }
        if(temp->left!=NULL && temp->right==NULL){
            node* dummy=temp->left;
            delete temp;
            return dummy;
        }
        if(temp->left!=NULL && temp->right!=NULL){
            int dummy=min(root->right)->data;
            temp->data=dummy;
            temp->right=deleteFromBst(temp->right,dummy);
        }
    }
    else if(temp->data>val){
        temp->left=deleteFromBst(temp->left,val);
        // return temp;
    }
    else if(temp->data<val){
        temp->right=deleteFromBst(temp->right,val);
    }
        return temp;
}
int main(){
    BST b1;
    b1.take_input();
    b1.inorder(b1.root);
    cout<<endl;
    b1.deleteFromBst(b1.root,5);
    b1.inorder(b1.root);
}