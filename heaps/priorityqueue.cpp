#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int>pq;
    pq.push(4);
    pq.push(1);
    pq.push(5);
    pq.push(2);
    cout<<"\ntop element is:"<<pq.top();
    cout<<"\nsize element is:"<<pq.size();

    cout<<"\n minheap:";
    priority_queue<int,vector<int>,greater<int>>mn;
    mn.push(4);
    mn.push(1);
    mn.push(5);
    mn.push(2);
    cout<<"\ntop element is:"<<mn.top();
    cout<<"\nsize element is:"<<mn.size();
}