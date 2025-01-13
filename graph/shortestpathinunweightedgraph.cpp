//{ Driver Code Starts
// Initial Template for C++


//imp
//done using bfs

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        unordered_map<int,int>adj;
        for(int i=0;i<N;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_map<int ,bool>visited;
        unordered_map<int,int>parent;
        parent[src]=-1;
        visited[src]=true;
        queue<int>q;
        q.push(src);
        
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto neighbour:adj[front]){
                if(!visited[front]){
                    visited[neighbour]=true;
                    parent[neighbour]=front;
                    q.push(neighbour);
                }
                
            }
        }
        
        int currentNode=endnode;
        vector<int>ans;
        ans.push_back(currentNode);
        while(currentNode!=src){
            currentNode=parent[currentNode];
            ans.push_back(currentNode);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends