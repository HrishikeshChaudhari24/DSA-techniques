#include<iostream>
using namespace std;

void selectionsort(int arr[],int n){
    for(int i=1;i<n;i++){
       int tmp=arr[i];
       int j=i-1;
       while(j>=0){
        if(arr[j]>tmp){
            arr[j+1]=arr[j];
        }
        else{
            break;
        }
        j--;
       } 
       arr[j+1]=tmp;
    }
}
int main(){
    int arr[5]={64,25,12,22,11};
    selectionsort(arr,5);
    cout<<"\nsorted array is:";
    for(int i=0;i<5;i++){
        cout<<arr[i]<<"  ";
    }
}