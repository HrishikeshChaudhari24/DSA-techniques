#include<iostream>
using namespace std;

void selectionSort(int arr[],int size,int minindx){
    if(size==0 || size==1){
        return;
    }
    minindx=0;
    for(int i=1;i<size;i++){
        if(arr[minindx]>arr[i]){
            minindx=i;
        }
    }
    swap(arr[minindx],arr[0]);
    selectionSort(arr+1,size-1,0);
}
int main(){
    int arr[]={6,5,4,3,2,1};
    int n=6;
    selectionSort(arr,n,0);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}