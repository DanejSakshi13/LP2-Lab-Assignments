#include <iostream>
#include <set>
#include <vector>
#include <limits>

using namespace std;

const int inf = 1e7;
const int MAXN = 1005; // Adjust the maximum number of vertices as needed

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    vector<int> dist(n + 1, inf);
    vector<bool> visited(n + 1, false);

    // Construct the graph (adjacency list)
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // Assuming undirected graph
    }

    int src;
    cin >> src;
    dist[src] = 0;
    set<pair<int, int>> s;
    s.insert({0, src}); // {wt, vertex}

    // Prim's algorithm
    while (!s.empty()) {
        auto x = *(s.begin());
        s.erase(x);
        int u = x.second;
        visited[u] = true;
        for (auto& it : graph[u]) {
            int v = it.first;
            int weight = it.second;
            if (!visited[v] && dist[v] > weight) {
                s.erase({dist[v], v});
                dist[v] = weight;
                s.insert({dist[v], v});
            }
        }
    }

    // Print the minimum spanning tree edges and their weights
    for (int i = 1; i <= n; ++i) {
        if (i != src) {
            cout << i << " " << dist[i] << endl;
        }
    }

    return 0;
}
