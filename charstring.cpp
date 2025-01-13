#include<iostream>
#include<cstring>
using namespace std;

void stringrev(char arr[],int len){
    int s=0;
    int e=len-1;
    while(s<e){
        swap(arr[s++],arr[e--]);
    }
    // for(int i=len;i>=0;i--){
    //     cout<<arr[i];
    // }
}
int main(){
    char arr[6];
    cout<<"\nenter the name;";
    cin>>arr;
    int len=strlen(arr);
    stringrev(arr,len);

}