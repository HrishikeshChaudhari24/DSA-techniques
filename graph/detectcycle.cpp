#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <unordered_map>
#include<stack>
using namespace std;

// Function to perform Breadth-First Search (BFS) to detect cycles
bool BFS(int** &graph, int numNodes) {
    vector<bool> visited(numNodes, false);
    queue<int> bfsQueue;
    unordered_map<int, int> parent;

    for (int startNode = 0; startNode < numNodes; startNode++) {
        if (!visited[startNode]) {
            bfsQueue.push(startNode);
            visited[startNode] = true;
            // parent[startNode] = -1;

            while (!bfsQueue.empty()) {
                int currentNode = bfsQueue.front();
                bfsQueue.pop();

                for (int neighbor = 0; neighbor < numNodes; ++neighbor) {
                    if (graph[currentNode][neighbor] == 1) {
                        if (!visited[neighbor]) {
                            bfsQueue.push(neighbor);
                            visited[neighbor] = true;
                            parent[neighbor] = currentNode;
                        } else if (neighbor != parent[currentNode]) {
                            // A cycle is detected
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool DFS(int** graph, int numNodes) {
    vector<bool> visited(numNodes, false);
    stack<int> dfsStack;
    unordered_map<int, int> parent;
    cout << "DFS traversal for the entire graph: ";

    for (int startNode = 0; startNode < numNodes; ++startNode) {
        if (!visited[startNode]) {
            dfsStack.push(startNode);
            visited[startNode] = true;

            while (!dfsStack.empty()) {
                int currentNode = dfsStack.top();
                dfsStack.pop();

                cout << currentNode << " ";

                for (int neighbor = 0; neighbor < numNodes; ++neighbor) {
                    if(graph[currentNode][neighbor]==1){
                        if (graph[currentNode][neighbor] == 1 && !visited[neighbor]) {
                            dfsStack.push(neighbor);
                            visited[neighbor] = true;
                            parent[neighbor]=currentNode;
                        }
                        else if(neighbor!=parent[currentNode]){
                            return true;
                        }

                    }
                }
            }
        }
    }

    cout << endl;
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

    // Performing BFS to detect cycles
    bool ans = BFS(adjacencyMatrix, numNodes);
    cout << "Cycle present or not using BFS? " << (ans ? "Yes" : "No") << endl;

     bool ans2 = DFS(adjacencyMatrix, numNodes);
    cout << "Cycle present or not using DFS? " << (ans2 ? "Yes" : "No") << endl;

    // Free allocated memory
    for (int i = 0; i < numNodes; ++i) {
        delete[] adjacencyMatrix[i];
    }
    delete[] adjacencyMatrix;

    return 0;
}
