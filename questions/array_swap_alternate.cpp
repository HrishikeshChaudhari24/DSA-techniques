//swap the alternate elemnets in the array
#include<iostream>
using namespace std;
void swapalternate(int arr[],int n){
    int count=0;
    for(int i=0;i<n;i=i+2){
        if(i<n && (i+1)<n){

            swap(arr[i],arr[i+1]);
        }else{
            break;
        }
    }
    cout<<"\nswaapped elements are:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[5]={1,2,3,4,5};
    swapalternate(arr,5);
}