#include<iostream>
using namespace std;
class heaps{
    public:
        int arr[100];
        int size=0;
        heaps(){
            arr[0]=-1;
            size=0;
        }
        void insert(int val);
        void heapify(int arr[],int size,int i);
        void deletion();
};
void heaps::insert(int val){
    size++;
    int index=size;
    arr[size]=val;
    while(index>1){
        int temp=index/2;
        if(arr[temp]<arr[index]){
            swap(arr[temp],arr[index]);
            index=temp;
        }
        else{
            return;
        }
    }
}
void heaps::heapify(int arr[],int size,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left <=size && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<=size && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,size,largest);
    }
}
void heaps::deletion(){
    int i=1;
    arr[i]=arr[size];
    size--;
    while(i<size){
        int left=2*i;
        int right=2*i+1;
        int indx=i;
        if(right<=size && arr[left]<arr[right]){
            indx=right;
        }
        else if(left<=size && arr[left]>arr[right]){
            indx=left;
        }
        else{
            return;
        }
        if(arr[i]<arr[indx]){
            swap(arr[i],arr[indx]);
            i=indx;
        }
        else{
            return;
        }
    }
    // return;
}