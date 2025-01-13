#include<iostream>
using namespace std;
class node{
    public:
        int data=0;
        node* left=NULL;
        node* right=NULL;
        int height=0;
        node(int data){
            this->data=data;
            left=right=NULL;
            height=1;
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
        node* leftRotate(node* x);
        node* rightRotate(node* y); 
        int giveHeight(node* temp){
            if(temp==NULL){
                return 0;
            }
            return temp->height;
        }
        int getBalance(node* temp){
            if(temp==NULL){
                return 0;
            }
            return giveHeight(temp->left)-giveHeight(temp->right);
        }
        void preOrder(node *root) { 
            if (root != NULL) { 
                cout << root->data << " "; 
                preOrder(root->left); 
                preOrder(root->right); 
            } 
        } 

};

node* BST::rightRotate(node* y){
    node* x=y->left;
    node* t2=x->right;

    x->right=y;
    y->left=t2;

    y->height=1+max(giveHeight(y->left),giveHeight(y->right));
    x->height=1+max(giveHeight(x->left),giveHeight(x->right));
    return x;
}

node* BST::leftRotate(node* x){
    node* y=x->right;
    node* t2=y->left;

    y->left=x;
    x->right=t2;

    y->height=1+max(giveHeight(y->left),giveHeight(y->right));
    x->height=1+max(giveHeight(x->left),giveHeight(x->right));
    return y;
}
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
    else{
        return root;
    }
    root->height=1+max(giveHeight(root->left),giveHeight(root->right));
    int balance=getBalance(root);
    if(balance>1 && data<root->left->data){
            return rightRotate(root);
    }
    if(balance < -1 && data>root->right->data){
         return leftRotate(root);
    }
    if(balance>1 && data>root->left->data){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance < -1 && data<root->right->data){
        root->right=rightRotate(root->right);
        return leftRotate(root);
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
    cout<<endl;
    b1.preOrder(b1.root);
}