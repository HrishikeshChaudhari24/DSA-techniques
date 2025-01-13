#include<iostream>
using namespace std;
// number pattern
// int main(){
//     int a=0;
//     for(int i=0;i<4;i++){
//         for(int j=0;j<4;j++){
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }   
// }

// star pattern
// int main(){
//     for(int i=0;i<4;i++){
//         for(int j=0;j<i;j++){
//             cout<<"*"<<" ";
//         }
//         cout<<endl;
//     }
// }

// star descending pattern
int main(){
    int j;
    for(int i=0;i<4;i++){
        for(j=0;j<i;j++){
            cout<<" ";
        }

        for(int k=4;k>i;k--){
            cout<<"*"<<" "; 
        }
        cout<<endl;
    }
}

