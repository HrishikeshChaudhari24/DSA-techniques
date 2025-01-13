#include<iostream>
using namespace std;
void selectionsort(int arr[],int size){
    int n=size;
    int minindx=0;
    int swap=0;
    for(int i=0;i<n;i++){
        minindx=i;
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                minindx=j;
            }
        }
        swap=arr[i];
        arr[i]=arr[minindx];
        arr[minindx]=swap;

    }
}
int main(){
    int arr[5]={64,25,12,22,11};
    cout<<"\nselection sort:";
    selectionsort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}