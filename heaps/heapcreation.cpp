#include<iostream>
using namespace std;
class heap{
    public:
        int arr[100];
        int size;
        heap(){
            arr[0]=-1;
            size=0;
        }
        void insert(int val);
        void deletion();
        // void heapify(int arr[],int n,int i);
        void print(){
            for(int i=0;i<=size;i++){
                cout<<arr[i]<<" ";
            }
        }
};
void heap::insert(int val) { //O(logn)
    size = size + 1;
    int index = size;
    arr[index] = val;
    while (index > 1) {
        int parent = index / 2;
        if (arr[parent] < arr[index] ) {
            swap(arr[parent], arr[index]);
            index = parent;
        } else {
            return;
        }
    }
}

void heap::deletion(){
    arr[1]=arr[size];
    size--;
    int i=1;
    while(i<size){
        int leftIndex=2*i;
        int rightIndex=2*i+1;
        int maxindx=i;
        if(leftIndex<size && arr[leftIndex]>arr[rightIndex]){
            maxindx=leftIndex;
        }
        else if(rightIndex<size && arr[leftIndex]<arr[rightIndex]){
            maxindx=rightIndex;
        }
        else{
            return;
        }
        if( arr[i]<arr[maxindx]){
            swap(arr[i],arr[maxindx]);
            i=maxindx;
        }
        
        else{
            return;
        }
    }
}
void heapify(int arr[],int n,int i){  //O(logn)
    int largest=i;
    int left=2*i;
    int right=(2*i)+1;
    if(left<=n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest=right;
    }

    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);//down the tree validation of heap property
    }
}
void heapsort(int arr[],int n){  //O(nlogn)
    int size=n;
    while(size>1){
        swap(arr[1],arr[size]);
        size--;

        heapify(arr,size,1);

    }
}
int main(){
    heap h1;
    h1.insert(50);
    h1.insert(51);
    h1.insert(52);
    h1.insert(53);
    h1.insert(54);
    h1.insert(56);
    h1.print();
    cout<<"deleted";
    h1.deletion();
    cout<<endl;
    h1.print();
    int arr[7]={-1,1,5,9,10,6,12};
    int n=6;
    // for(int i=n/2;i>0;i--){ //O(n)
    //     heapify(arr,n,i);
    // }
    cout<<endl;
    for(int i=0;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // time complexity for building the heap is O(n) using heapify algo
    cout<<"sorted array is:";
    heapsort(arr,n);
    for(int i=0;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    
}