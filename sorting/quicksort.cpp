#include<iostream>
using namespace std; 

int partition(int *arr,int low,int high){
    int pivot=arr[low];
    int cnt=0;
    for(int i=low+1;i<=high;i++){
        if(arr[i]<=pivot){
            cnt++;
        }
    }
    int pivotindx=low+cnt;
    swap(arr[low],arr[pivotindx]);
    int i=low;
    int j=high;
    cout<<pivotindx;
    while(i<pivotindx && j>pivotindx){
        while(arr[i]<=pivot && i<pivotindx){
            i++;
        }
        while(arr[j]>=pivot && j>pivotindx){
            j--;
        }
        if(i<pivotindx && j>pivotindx){
            swap(arr[i],arr[j]);
        }
    }
    return pivotindx;
}
void quicksort(int *arr,int low,int high){
    if(low>=high){
        return;
    }
    int p=partition(arr,low,high);
    quicksort(arr,low,p-1);
    quicksort(arr,p+1,high);
}
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}