#include<iostream>
using namespace std;
class Node{
    public:
    Node* left=NULL;
    Node* right=NULL;
    int data;
};
class bst{
    public:
        Node* root=NULL;
        void takeinput();
        Node* buildTree(Node* &root,int data);
        void inorder(Node* root);
        Node* min(Node* temp);
        Node* deletefrombst(Node* root,int val);
};
Node* bst::buildTree(Node* &root,int data){
    if(root==NULL){
        root=new Node;
        root->data=data;
        return root;
    }
    if(data > root->data){
        root->right=buildTree(root->right,data);
    }
    else{
        root->left=buildTree(root->left,data);
    }
    return root;
}
void bst::takeinput(){
    int data;
    cin>>data;
    while(data!=-1){
        root=buildTree(root,data);
        
        cin>>data;
    }
}
void bst::inorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);
}
Node* bst::min(Node* temp){
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
Node* bst::deletefrombst(Node* root,int val){
    if(root==NULL){
        return root;
    }
    if(root->data==val){
        //with zero child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //with 1 child
        //left child
        if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->left==NULL && root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }

        //with both child NULL
        if(root->left!=NULL && root->right!=NULL){
            int mini=min(root->right)->data;
            root->data=mini;
            root->right=deletefrombst(root->right,mini);
        }
    }
    else if(root->data > val){
        root->left=deletefrombst(root->left,val);
    }
    else{
        root->right=deletefrombst(root->right,val);
    }
    return root;
}
int main(){
    bst b1;
    b1.takeinput();
    cout<<endl;
    b1.inorder(b1.root);
    cout<<"\nmin value in tree is:"<<(b1.min(b1.root))->data<<endl;
    b1.root=b1.deletefrombst(b1.root,20);
    b1.inorder(b1.root);
    cout<<"\ndata:"<<b1.root->data;
}