#include<iostream>
#include<string.h>
using namespace std;
class Phone{
    public:
        int price;
        // string name=new string;
        char *name=new char[100];
        
        Phone(){
            cout<<"";
        }
        Phone(Phone &temp){
            char *name1=new char[100];
            strcpy(name1,temp.name);
            // cout<<"name1"<<name1;
            strcpy(this->name,name1);
        }

        void show(){
            cout<<"Phone Name:"<<name<<endl;
            cout<<"Phone Price:"<<price<<endl;
        }
        
};
int main(){
    Phone p1;
    strcpy(p1.name,"Samsung");
    p1.price=10000;
    p1.show();
    Phone p2(p1);
    strcpy(p1.name,"tamsung");
    // p2.price=5000;
    p2.show();
    p1.show();
}