#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>
#include <algorithm>

using namespace std;
struct Node {
    int id;
    double heuristic;
    double cost; 
};

struct Edge {
    int to;
    double cost;
};

struct CompareNode {
    bool operator()(const Node& a, const Node& b) {
        return a.heuristic + a.cost > b.heuristic + b.cost;
    }
};

vector<int> astar(const vector<vector<Edge>>& graph, int start, int goal, const vector<double>& heuristic) {
    priority_queue<Node, vector<Node>, CompareNode> pq;

    unordered_map<int, double> cost_so_far;

    unordered_map<int, int> came_from;

    Node start_node = {start, heuristic[start], 0.0};
    pq.push(start_node);
    cost_so_far[start] = 0.0;

    // A* search
    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if (current.id == goal) {
            vector<int> path;
            int node = goal;
            while (node != start) {
                path.push_back(node);
                node = came_from[node];
            }
            path.push_back(start);
            reverse(path.begin(), path.end());
            return path;
        }

        for (const Edge& edge : graph[current.id]) {
            double new_cost = cost_so_far[current.id] + edge.cost;
            if (!cost_so_far.count(edge.to) || new_cost < cost_so_far[edge.to]) {
                cost_so_far[edge.to] = new_cost;
                Node next = {edge.to, heuristic[edge.to], new_cost};
                pq.push(next);
                came_from[edge.to] = current.id;
            }
        }
    }

    return vector<int>();
}

int main() {
    int num_nodes, num_edges;
    cout << "Enter the number of nodes and edges: ";
    cin >> num_nodes >> num_edges;

    vector<vector<Edge>> graph(num_nodes);

    cout << "Enter the edges and their costs (source destination cost):" << endl;
    for (int i = 0; i < num_edges; ++i) {
        int source, destination;
        double cost;
        cin >> source >> destination >> cost;
        graph[source].push_back({destination, cost});
    }

    vector<double> heuristic(num_nodes);
    cout << "Enter heuristic values for each node:" << endl;
    for (int i = 0; i < num_nodes; ++i) {
        cout << "Node " << i << ": ";
        cin >> heuristic[i];
    }

    int start, goal;
    cout << "Enter the start node and the goal node: ";
    cin >> start >> goal;

    vector<int> path = astar(graph, start, goal, heuristic);

    if (!path.empty()) {
        cout << "Path found: ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "Path not found" << endl;
    }

    return 0;
}









/*
Sample input
Enter the number of nodes and edges: 6 9
Enter the edges and their costs (source destination cost):
0 1 5
0 2 3
1 3 6
1 4 8
2 3 2
3 5 7
4 5 4
2 1 1
3 0 2
Enter heuristic values for each node:
Node 0: 9
Node 1: 6
Node 2: 4
Node 3: 2
Node 4: 2
Node 5: 0
Enter the start node and the goal node: 0 5



OUTPUT 
Path found: 0 2 3 5 
*/