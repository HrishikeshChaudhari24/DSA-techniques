// time complexity=O(n);
// n no of comparision are done in worst case

#include<iostream>
using namespace std;
int linearsearch(int arr[],int size,int key){
    for(int i=0;i<size;i++){
        if(key==arr[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[6]={3,8,11,20,70,91};
    int index = linearsearch(arr,6,9);
    cout<<"\nthe no 6 is located at index:"<<index;
}