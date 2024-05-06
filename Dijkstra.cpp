#include <iostream>
#include <set>
#include <limits>

using namespace std;

const int inf = 1e7;
const int MAXN = 1005; // Adjust the maximum number of vertices as needed

int main() {
    int n, m;
    cin >> n >> m;
    int dist[MAXN][MAXN];
    set<pair<int, int>> s;

    // Initialize distances to all vertices as infinity
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dist[i][j] = inf;
        }
    }

    // Construct the graph (adjacency matrix)
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
        dist[v][u] = w; // Assuming undirected graph
    }

    int src;
    cin >> src;
    dist[src][src] = 0;
    s.insert({0, src}); // {wt, vertex}

    // Dijkstra's algorithm
    while (!s.empty()) {
        auto x = *(s.begin());
        s.erase(x);
        int u = x.second;
        for (int v = 1; v <= n; ++v) {
            int weight = dist[u][v];
            if (weight != inf) {
                if (dist[v][u] > dist[u][v] + weight) {
                    s.erase({dist[v][u], v});
                    dist[v][u] = dist[u][v] + weight;
                    s.insert({dist[v][u], v});
                }
            }
        }
    }

    // Print the shortest distances from the start vertex
    for (int i = 1; i <= n; ++i) {
        if (dist[src][i] < inf) {
            cout << dist[src][i] << " ";
        } else {
            cout << -1 << " ";
        }
    }

    return 0;
}