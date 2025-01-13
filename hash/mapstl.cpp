#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string,int>m;

    // insertion methods
    // 1
    pair<string,int>p=make_pair("hello",1);
    m.insert(p);
    // 2
    pair<string,int>p2("hello2",2);
    m.insert(p2);
    //3
    m["bye"]=3;
    //search
    cout<<m["bye"]<<endl;
    cout<<m.at("bye")<<endl;
    //size
    cout<<m.size()<<endl;
    cout<<m["love"]<<endl;//creates a new entry
    cout<<m.at("love")<<endl;
    cout<<m.erase("love")<<endl;
    // cout<<m.at("love")<<endl;
    unordered_map<string,int>::iterator it=m.begin();
    while(it!=m.end()){
        cout<<it->first<<"  "<<it->second<<endl;
        it++; 
    }
    //order of content is not preserved in unordered map
}