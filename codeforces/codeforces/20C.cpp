/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Shivam            |
 |                                        |
  ------------------------------------------
    \        ,     ,        /
      \      |     |      /
         \   \_/   /
           \  -----  /
             \_/

  Happy coding!
*/

#include <bits/stdc++.h>
using namespace std;
using pii = pair<long long, int>;
const long long INF = LLONG_MAX;

// -------------------------------- Dijkstra with Path Reconstruction --------------------------------
vector<int> dijkstra_with_path(int n, vector<vector<int>> &edges, int src, int dest) {
    vector<vector<pii>> adj(n);
    for (auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected
    }

    // Step 1: Initialize distances and parent array
    vector<long long> dist(n, INF);
    vector<int> parent(n, -1);
    dist[src] = 0;
    parent[src] = src;

    // Step 2: Min-heap priority queue {distance, node}
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});

    // Step 3: Dijkstra's algorithm
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue; // outdated entry
        if (u == dest) break;      // early stopping when reaching dest

        for (auto [v, w] : adj[u]) {
            if (d + w < dist[v]) {
                dist[v] = d + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // Step 4: Reconstruct path from dest to src
    if (dist[dest] == INF) return {}; // no path found

    vector<int> path;
    for (int cur = dest; cur != src; cur = parent[cur]) {
        path.push_back(cur);
    }
    path.push_back(src);
    reverse(path.begin(), path.end());
    return path;
}
// ---------------------------------------------------------------------------------------------------------

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    edges.reserve(m);

    // Read all edges (1-based input → convert to 0-based)
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        edges.push_back({u, v, w});
    }

    // Run Dijkstra from vertex 1 (0) to vertex n (n-1)
    vector<int> path = dijkstra_with_path(n, edges, 0, n - 1);

    if (path.empty()) {
        cout << -1 << "\n";
    } else {
        for (int node : path) {
            cout << (node + 1) << " "; // convert back to 1-based
        }
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
