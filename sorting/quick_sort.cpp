#include<iostream>
#include<vector>
using namespace std;

// approach 1 for partition

// int partition(vector<int>&arr,int low,int high){
//     int pivot = arr[high];
//     int i=low-1;
//     for(int j=low;j<=high;j++){
//         if(arr[j]<pivot){
//             i++;
//             swap(arr[i],arr[j]);
//         }
//     }
//     swap(arr[i+1],arr[high]);
//     return i+1;
// }

// approach 2 for partition

int partition(vector<int>&arr,int low,int high){
    int pivot=arr[low];
    int cnt=0;
    for(int i=low+1;i<=high;i++){
        if(arr[i]<pivot){
            cnt++;
        }
    }

    int pivotIndex=low+cnt;
    swap(arr[pivotIndex],arr[low]);

    int i=low,j=high;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>=pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(vector<int>&arr,int low,int high){
    if(low<high){
        int pivot=partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
}
int main(){
    vector<int>arr={9,8,11,1,15,2,2,2,2};
    int n=arr.size();
    quickSort(arr,0,n-1);
    cout<<"\nSorted array:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
}