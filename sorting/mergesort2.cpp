// this code is inplace alogorithm approach
#include<iostream>
using namespace std;
int swap1=0;
void merge(int arr[],int s,int mid,int e){
    int left=s;
    int right=mid+1;
    if(arr[mid]<=arr[right]){
            return;
        }
    while(left<=mid && right<=e){
        if(arr[left]<=arr[right]){
            left++;
           
        }
        else{
            int i=right;
            // int j=i-1;
          
            while(i!=left){
                
               swap(arr[i],arr[i-1]);
               
                i--;
            }
           
            left++;
            right++;
            mid++;
            

        }
    }
}
void mergeSort(int arr[],int s,int e){
   
    if(s<e){
    int mid=(s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);

    merge(arr,s,mid,e);
    }
}
int main(){
    int arr[]={10, 19, 6, 3, 5};
    int n=5;
    mergeSort(arr,0,n-1);
    cout<<endl;

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<swap1;
}