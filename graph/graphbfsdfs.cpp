#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

// Function to perform Breadth-First Search (BFS)
void BFS(int** &graph, int numNodes) {
    vector<bool> visited(numNodes, false);
    queue<int> bfsQueue;

    // cout << "BFS traversal starting from node " << startNode << ": ";
    for(int startNode=0;startNode<numNodes;startNode++){
        if(!visited[startNode]){

            bfsQueue.push(startNode);
            visited[startNode] = true;

            while (!bfsQueue.empty()) {
                int currentNode = bfsQueue.front();
                bfsQueue.pop();

                cout << currentNode << " ";

                for (int neighbor = 0; neighbor < numNodes; ++neighbor) {
                    if (graph[currentNode][neighbor] == 1 && !visited[neighbor]) {
                        bfsQueue.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
        }   
    }

    cout << endl;
}

// Function to perform Depth-First Search (DFS)
void DFS(int** graph, int numNodes) {
    vector<bool> visited(numNodes, false);
    stack<int> dfsStack;

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
                    if (graph[currentNode][neighbor] == 1 && !visited[neighbor]) {
                        dfsStack.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
        }
    }

    cout << endl;
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
    int **adjacencyMatrix=new int*[numNodes];
    for(int i=0;i<numNodes;i++){
        adjacencyMatrix[i]=new int[numNodes];
    }

    for (int i = 0; i < numNodes; ++i) {
        for (int j = 0; j < numNodes; ++j) {
            inputFile >> adjacencyMatrix[i][j];
        }
    }
    int start=0;
    inputFile>>start;
    cout<<"\nvalue of start:"<<start<<endl;
    inputFile.close();

    // Example: Performing BFS and DFS starting from node 0
    BFS(adjacencyMatrix, numNodes);
    DFS(adjacencyMatrix, numNodes);

    return 0;
}
