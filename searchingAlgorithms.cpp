/*SAKSHI GANESH DANEJ (TE_B_17)*/


#include <iostream>
#include <queue>
#include <stack>
using namespace std;

#define MAX_NODES 100

// Adjacency matrix representation of the graph
int graph[MAX_NODES][MAX_NODES];
int numNodes;

//Breadth-First Search traversal
void bfs(int start) {
    bool visited[MAX_NODES] = {false};
    queue<int> q;
    q.push(start);
    visited[start] = true;
    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int current = q.front();
        cout << current << " ";
        q.pop();
        for (int i = 0; i < numNodes; ++i) {
            if (graph[current][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    cout << endl;
}

//Depth-First Search traversal
void dfs(int start) {
    bool visited[MAX_NODES] = {false};
    stack<int> s;
    s.push(start);
    visited[start] = true;
    cout << "DFS Traversal: ";
    while (!s.empty()) {
        int current = s.top();
        s.pop();
        cout << current << " ";
        for (int i = numNodes - 1; i >= 0; --i) {
            if (graph[current][i] && !visited[i]) {
                s.push(i);
                visited[i] = true;
            }
        }
    }
    cout << endl;
}

int main() {
    int choice, startNode;

    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < numNodes; ++i) {
        for (int j = 0; j < numNodes; ++j) {
            cin >> graph[i][j];
        }
    }

    do {
        cout << "Menu:\n";
        cout << "1. BFS Traversal\n";
        cout << "2. DFS Traversal\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the starting node for BFS traversal: ";
                cin >> startNode;
                bfs(startNode);
                break;
            case 2:
                cout << "Enter the starting node for DFS traversal: ";
                cin >> startNode;
                dfs(startNode);
                break;
            case 3:
                cout << "Exiting program...";
                break;
            default:
                cout << "Invalid choice!";
        }
        cout << endl;

    } while (choice != 3);

    return 0;
}





/*

OUTPUT

Enter the number of nodes: 5
Enter the adjacency matrix:
0 1 1 0 0
1 0 0 1 1
1 0 0 0 0
0 1 0 0 0
0 1 0 0 0
Menu:
1. BFS Traversal
2. DFS Traversal
3. Exit
Enter your choice: 1
Enter the starting node for BFS traversal: 0

BFS Traversal: 0 1 2 3 4



Menu:
1. BFS Traversal
2. DFS Traversal
3. Exit
Enter your choice: 2
Enter the starting node for DFS traversal: 0
DFS Traversal: 0 2 1 4 3


Menu:
1. BFS Traversal
2. DFS Traversal
3. Exit
Enter your choice: 3

Exiting program...
*/