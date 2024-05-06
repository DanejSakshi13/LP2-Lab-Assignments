#include <iostream>

#include <vector>

#include <algorithm>

#include <queue>

#include <limits>

#include <set>



using namespace std;



const int INF = numeric_limits<int>::max();



class Graph {

  int V;

  vector<vector<pair<int, int>>> adj;



public:

  Graph(int vertices) : V(vertices), adj(vertices) {}



  void add_edge(int u, int v, int w) {

    adj[u].push_back({v, w});

    adj[v].push_back({u, w});

  }



  void prim_mst() {

    vector<bool> inMST(V, false);

    vector<int> parent(V, -1);

    vector<int> key(V, INF);



    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;



    int src = 0; // Start from vertex 0

    pq.push({0, src});

    key[src] = 0;



    while (!pq.empty()) {

      int u = pq.top().second;

      pq.pop();



      inMST[u] = true;



      for (auto& edge : adj[u]) {

        int v = edge.first;

        int weight = edge.second;



        if (!inMST[v] && weight < key[v]) {

          key[v] = weight;

          parent[v] = u;

          pq.push({key[v], v});

        }

      }

    }



    cout << "Prim's Minimal Spanning Tree:" << endl;

    for (int i = 1; i < V; ++i)

      cout << parent[i] << " - " << i << " \n"[i == V - 1];

  }



  void kruskal_mst() {

    vector<pair<int, pair<int, int>>> edges;

    for (int u = 0; u < V; ++u) {

      for (auto& edge : adj[u]) {

        int v = edge.first;

        int weight = edge.second;

        edges.push_back({weight, {u, v}});

      }

    }



    sort(edges.begin(), edges.end());



    vector<int> parent(V);

    for (int i = 0; i < V; ++i)

      parent[i] = i;



    int mstWeight = 0;

    cout << "Kruskal's Minimal Spanning Tree:" << endl;

    for (auto& edge : edges) {

      int weight = edge.first;

      int u = edge.second.first;

      int v = edge.second.second;



      int setU = find(parent, u);

      int setV = find(parent, v);



      if (setU != setV) {

        cout << u << " - " << v << endl;

        mstWeight += weight;

        unionSets(parent, setU, setV);

      }

    }

  }



  int find(vector<int>& parent, int u) {

    if (parent[u] != u)

      parent[u] = find(parent, parent[u]);

    return parent[u];

  }



  void unionSets(vector<int>& parent, int u, int v) {

    parent[u] = v;

  }



  void dijkstra(int src) {

    vector<int> dist(V, INF);

    vector<bool> visited(V, false);



    dist[src] = 0;



    for (int count = 0; count < V - 1; ++count) {

      int u = -1;

      for (int i = 0; i < V; ++i) {

        if (!visited[i] && (u == -1 || dist[i] < dist[u]))

          u = i;

      }



      visited[u] = true;



      for (auto& edge : adj[u]) {

        int v = edge.first;

        int weight = edge.second;

        if (!visited[v] && dist[u] + weight < dist[v])

          dist[v] = dist[u] + weight;

      }

    }



    cout << "Shortest distances from source vertex " << src << ":" << endl;

    for (int i = 0; i < V; ++i) {

      cout << "Vertex " << i << ": ";

      if (dist[i] != INF)

        cout << dist[i] << endl;

      else

        cout << "INF" << endl;

    }

  }

};



int main() {

  cout << "MENU" << endl;

  cout << "1. Prim's Minimal Spanning Tree Algorithm" << endl;

  cout << "2. Kruskal's Minimal Spanning Tree Algorithm" << endl;

  cout << "3. Dijkstra's Algorithm" << endl;

  cout << "4. Exit" << endl;



  int choice;

  cin >> choice;



  if (choice == 4)

    return 0;



  int vertices;

  cout << "Enter the number of vertices: ";

  cin >> vertices;

  Graph g(vertices);



  int u, v, w;

  cout << "Enter edges (u v w), -1 to stop: " << endl;

  while (true) {

    cin >> u >> v >> w;

    if (u == -1)

      break;

    g.add_edge(u, v, w);

  }



  if (choice == 1)

    g.prim_mst();

  else if (choice == 2)

    g.kruskal_mst();

  else if (choice == 3) {

    int src;

    cout << "Enter the source vertex: ";

    cin >> src;

    g.dijkstra(src);

  } else

    cout << "Invalid choice!" << endl;



  return 0;

}



