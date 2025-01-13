#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
        int data;
        node *left=NULL;
        node *right=NULL;
        node(int data){
            this->data=data;
        }

};
class BT{
    public:
        node* root=NULL;
        node* buildTree(node* &root);
        void inorder(node *root);
        node* deletion(node* temp,int data);
        void deleteDeepest(node* temp,node* key_node);
        
};
node* BT::buildTree(node* &root){
    int data=0;
    cin>>data;
    
    if(data==-1){
        return NULL;
    }
    root=new node(data);
    
    cout<<"\nenter the data to left of"<<data<<":";
    root->left=buildTree(root->left);
    cout<<"\nenter the data to right of"<<data<<":";
    root->right=buildTree(root->right);
    return root;
}


void BT::inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void BT::deleteDeepest(node* temp,node* key_node){
    node* dummy=NULL;
    queue<node*> q;
    q.push(temp);
    while(!q.empty()){
        dummy=q.front();
        q.pop();
        if(dummy==key_node){
            dummy=NULL;
            delete(key_node);
            return;
        }
        if(dummy->left){
            if(dummy->left==key_node){
                dummy->left=NULL;
                delete(key_node);
                return;
            }
            else{
                q.push(dummy->left);
            }
        }
        if(dummy->right){
            if(dummy->right==key_node){
                dummy->right=NULL;
                delete(key_node);
                return;
            }
            else{
                q.push(dummy->right);
            }
        }
    }
}
node* BT::deletion(node* temp,int data){
    if(temp==NULL){
        return NULL;
    }
    if(temp->left==NULL && temp->right==NULL){
        if(temp->data==data){
            return NULL;
        }
        else{
            return temp;
        }
    }
    queue<node*>q;
    node* keynode=NULL;
    node* dummy=NULL;
    q.push(temp);
    while(!q.empty()){
        dummy=q.front();
        q.pop();
        if(dummy->data==data){
            keynode=dummy;
        }
        if(dummy->left!=NULL){
            q.push(dummy->left);
        }
        if(dummy->right!=NULL){
            q.push(dummy->right);
        }
    }
    if(keynode!=NULL){
        keynode->data=dummy->data;
        deleteDeepest(temp,dummy);
    }
    return temp;

}
int main(){
    BT b1;
    b1.buildTree(b1.root);
    b1.inorder(b1.root);
    cout<<endl;
    b1.deletion(b1.root,1);
    b1.inorder(b1.root);
}