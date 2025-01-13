#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class node{
    public:
        int data;
        node* left=NULL;
        node* right=NULL;
};
class binarytree{
    public:
        node* root=NULL;
        node* buildtree(node* root);
        void buildusinglevelorder(node* &root);
        void levelordertraversal(node* root);
        void inorder(node* temp);
        void preorder(node* temp);
        void postorder(node* temp);       
};
node* binarytree::buildtree(node* root){
    int data1;
    cout<<"\nenter the data:";
    cin>>data1;
    root=new node;
    if(data1==-1){
        return NULL;
    }
    root->data=data1;
    cout<<"\nenter the data to the left of "<<data1<<endl;
    root->left=buildtree(root->left);
    cout<<"\nenter the data to the right of "<<data1<<endl;
    root->right=buildtree(root->right);
    return root;
}
void binarytree::levelordertraversal(node* root){
    vector<int>ans;
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    ans.push_back(root->data);
    // cout<<ans[0];
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
           
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    } 
    cout<<endl;  
    // cout<<ans[1];
    //     cout<<"Hello";
    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";
    // } 
    cout<<endl;
}
void binarytree::buildusinglevelorder(node* &root){
    queue<node*>q;
    int data1;
    cout<<"\nenter the data:";
    cin>>data1;
    root=new node;
    root->data=data1;
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        cout<<"enter the left node for:"<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        
        if(leftData!=-1){
            temp->left=new node;
            temp->left->data=leftData;
            q.push(temp->left);
        }
        cout<<"enter the right node for:"<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        
        if(rightData!=-1){
            temp->right=new node;
            temp->right->data=rightData;
            q.push(temp->right);
        }
    }
}
void binarytree::inorder(node* temp){
    if(temp==NULL){
        return; 
    }
    inorder(temp->left);
    cout<<temp->data<<" ";
    inorder(temp->right);
} 
void binarytree::preorder(node* temp){
    if(temp==NULL){
        return; 
    }
    cout<<temp->data<<" ";
    inorder(temp->left);
    inorder(temp->right);
} 
void binarytree::postorder(node* temp){
    if(temp==NULL){
        return; 
    }
    inorder(temp->left);
    inorder(temp->right);
    cout<<temp->data<<" ";
} 
int main(){
    binarytree b1;
    // b1.root=b1.buildtree(b1.root);
    b1.buildusinglevelorder(b1.root);
    // cout<<"\nvalueof root is:"<<b1.root->data<<endl;
    b1.levelordertraversal(b1.root);
    // b1.inorder(b1.root);
    cout<<endl;
    // b1.preorder(b1.root);
    cout<<endl;
    // b1.postorder(b1.root);
}