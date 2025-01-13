// time complexity is=O(log(n))
// less no comparisions are done
// the method is used when nos are in strictly ascending or descending order

#include<iostream>
using namespace std;
int binarysearch(int arr[],int size,int key){
    int mid;
    int start=0;
    int end=size-1;
    mid=(start+(end-start)/2);
    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        else if(key>arr[mid]){
            start=mid+1;
        }
        else if(key<arr[mid]){
            end=mid-1;
        }
        mid=(start+(end-start)/2);
    }
    return -1;
}
int main(){
    int arr[6]={3,8,11,20,70,91};
    int index = binarysearch(arr,6,91);
    cout<<"\nlocated at index:"<<index;


}