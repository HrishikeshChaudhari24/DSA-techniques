#include<iostream>
#include<unordered_map>
#include<map>
#include<list>
using namespace std;
template<typename T>

class graph{
    public:
        unordered_map<T,list<T>>adj;
        void create_graph(T u,T v,bool direction);
        void printData();
};
template<typename T>
void graph<T>::create_graph(T u,T v,bool direction){
    adj[u].push_back(v);
    if(direction==0){
        adj[v].push_back(u);
    }
}
template<typename T>
void graph<T>::printData(){
    for(auto i:adj){
        cout<<i.first<<" -> ";
        for(auto j:i.second){
            cout<<j<<" , ";
        }
        cout<<endl;
    }
}
int main(){
    graph <int> g;
    int n,m;
    cout<<"\nenter the no of node and edges:";
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.create_graph(u,v,0);
    }
    g.printData();
}