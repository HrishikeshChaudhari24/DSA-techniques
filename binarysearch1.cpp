#include<iostream>
using namespace std;
int firstoccur(int arr[],int key,int size){
    int s=0;
    int e=size-1;
    int mid=(s+e)/2;
    int ans;
    while (s<=e)
    {
        if(arr[mid]==key){
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]< key){
            s=mid+1;
        }
        else if(arr[mid]> key){
            e=mid-1;
        }
        mid=(s+e)/2;
    }
    return ans;
    

}
int lastoccur(int arr[],int key,int size){
    int s=0;
    int e=size-1;
    int mid=(s+e)/2;
    int ans;
    while (s<=e)
    {
        if(arr[mid]==key){
            ans=mid;
            s=mid+1;
        }
        else if(arr[mid]< key){
            s=mid+1;
        }
        else if(arr[mid]> key){
            e=mid-1;
        }
        mid=(s+e)/2;
    }
    return ans;
    

}

int main(){
    int arr[5]={1,2,3,3,5};
    int key;
    cout<<"\nenter the key:";
    cin>>key;
    firstoccur(arr,key,5);

}