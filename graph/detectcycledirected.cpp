#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

bool DFS(int** graph, int numNodes) {
    vector<bool> visited(numNodes, false);
    vector<bool> dfsVisited(numNodes, false);

    for (int startNode = 0; startNode < numNodes; ++startNode) {
        if (!visited[startNode]) {
            stack<int> dfsStack;
            dfsStack.push(startNode);

            while (!dfsStack.empty()) {
                int currentNode = dfsStack.top();
                dfsStack.pop();
                // cout<<"\ncurrentNode"<<currentNode<<endl;
                if (!visited[currentNode]) {
                    visited[currentNode] = true;
                    dfsVisited[currentNode] = true;
                    dfsStack.push(currentNode); // Push current node back to manage backtracking
                } else {
                    // If we encounter the node again, it means we are backtracking
                    // cout<<"\n"<<currentNode<<"  ";
                    dfsVisited[currentNode] = false;
                    continue;
                }

                for (int neighbor = 0; neighbor < numNodes; ++neighbor) {
                    if (graph[currentNode][neighbor] == 1) {
                        if (!visited[neighbor]) {
                            dfsStack.push(neighbor);
                        } else if (dfsVisited[neighbor]) {
                            // If the neighbor is visited and still in the current path, cycle detected
                            return true;
                        }
                    }
                }
            }
        }
    }
    cout<<endl;
    // for(auto i:dfsVisited){
    //     cout<<i<<" "; 
    // }
    cout<<endl;
    return false;
}

int main() {
    ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    int numNodes;
    inputFile >> numNodes;

    // Assuming the input file contains an adjacency matrix with 0s and 1s
    int **adjacencyMatrix = new int*[numNodes];
    for (int i = 0; i < numNodes; ++i) {
        adjacencyMatrix[i] = new int[numNodes];
    }

    for (int i = 0; i < numNodes; ++i) {
        for (int j = 0; j < numNodes; ++j) {
            inputFile >> adjacencyMatrix[i][j];
        }
    }
    int start = 0;
    inputFile >> start;
    cout << "Value of start: " << start << endl;
    inputFile.close();

    // Performing DFS to detect cycles
    bool ans = DFS(adjacencyMatrix, numNodes);
    cout << "Cycle present or not using DFS? " << (ans ? "Yes" : "No") << endl;

    // Free allocated memory
    for (int i = 0; i < numNodes; ++i) {
        delete[] adjacencyMatrix[i];
    }
    delete[] adjacencyMatrix;

    return 0;
}
