#include<iostream>
#include<vector>
using namespace std;
int solve(int arr[],int n,int i,int sum){
    if(n==0){
        return 0;
    }
    solve(arr+1,n-1,i,sum);
    i=i*10;
    int value=arr[0]*i;
    sum=sum+value;
    cout<<"\nsum::"<<sum;
    cout<<"\nvalue::"<<value;
    return sum;
}
int main(){
    int arr[]={9};
    int arr1[100];
    int n=1;
    int i=0.1;
    int sum=0;
    string value="";
    for(int i=0;i<n;i++){
        value=value+to_string(arr[i]);
    }
    cout<<"value is :"<<value;
    int val=stoi(value);
    cout<<"\nval"<<val;
    val=val+1;
    string ans=to_string(val);
    cout<<endl;

    cout<<"ans:"<<ans[0];
    for(int i=0;i<2;i++){
        // char v=ans[i];
        arr1[i]=(int)(ans[i])-(int)('0');
    }
    cout<<endl;
    for(int i=0;i<2;i++){
        cout<<arr1[i];
    }
    // int ans=solve(arr,n,i,sum);
    // cout<<"value:"<<ans;

}