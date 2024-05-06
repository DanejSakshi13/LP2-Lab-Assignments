#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Function to compare edges based on their weights
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

const int MAXN = 1005; // Adjust the maximum number of vertices as needed

int parent[MAXN]; // Array to store the parent of each vertex

// Function to find the parent of a vertex using path compression
int find(int u) {
    if (parent[u] == u) return u; // If the vertex is its own parent, return it
    return parent[u] = find(parent[u]); // Path compression: Set parent of u to the root
}

// Function to perform union operation of two sets using union by rank
void unionSets(int u, int v) {
    parent[find(u)] = find(v); // Set parent of u's root to the root of v
}

int main() {
    int n, m; // Number of vertices and edges
    cin >> n >> m; // Input number of vertices and edges
    vector<Edge> edges(m); // Vector to store all edges

    // Input the edges
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Sort the edges based on their weights in non-decreasing order
    sort(edges.begin(), edges.end(), compareEdges);

    // Initialize parent array for Union-Find
    for (int i = 1; i <= n; ++i) {
        parent[i] = i; // Each vertex is initially its own parent
    }

    vector<Edge> mstEdges; // Vector to store the edges of the minimum spanning tree
    int mstWeight = 0; // Total weight of the minimum spanning tree

    // Traverse through all the sorted edges
    for (int i = 0; i < m; ++i) {
        int u = edges[i].u, v = edges[i].v, weight = edges[i].weight; // Extract edge information
        if (find(u) != find(v)) { // If u and v belong to different sets
            unionSets(u, v); // Merge the sets containing u and v
            mstEdges.push_back(edges[i]); // Add the edge to the minimum spanning tree
            mstWeight += weight; // Update the total weight of the minimum spanning tree
        }
    }

    // Output the edges and weights of the minimum spanning tree
    cout << "Minimum Spanning Tree Edges and Weights:" << endl;
    for (const auto& edge : mstEdges) {
        cout << edge.u << " " << edge.v << " " << edge.weight << endl;
    }
    cout << "Total Weight of Minimum Spanning Tree: " << mstWeight << endl;

    return 0; // Exit the program
}
