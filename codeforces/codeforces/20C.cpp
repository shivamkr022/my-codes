/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Shivam     |
 |                                        |
  ------------------------------------------
    \        ,     ,        /
      \      |     |      /
         \   \_/   /
           \  -----  /
             \_/
  
  Happy coding! 
*/

/* includes and all */

#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#define print(v) do { \
                    cout << "vect--" << #v << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << v[i] << " "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

// Dijkstra with path reconstruction
vector<int> dijkstra_with_path(int n, vector<vector<int>> &edges, int src, int dest) {
    vector<pair<int, int>> adj[n + 1]; // 1-based indexing

    // Build undirected adjacency list
    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt}); // for undirected
    }

    vector<int> dis(n + 1, 1e18), parent(n + 1);
    for (int i = 1; i <= n; i++) parent[i] = i;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int curr_dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (curr_dis > dis[node]) continue; // skip outdated entries

        for (auto nbr : adj[node]) {
            int adj_node = nbr.first;
            int edge_wt = nbr.second;

            if (curr_dis + edge_wt < dis[adj_node]) {
                dis[adj_node] = curr_dis + edge_wt;
                parent[adj_node] = node;
                pq.push({dis[adj_node], adj_node});
            }
        }
    }

    if (dis[dest] == 1e18) return {}; // no path exists

    // Reconstruct path
    vector<int> path;
    int curr = dest;
    while (curr != parent[curr]) {
        path.push_back(curr);
        curr = parent[curr];
    }
    path.push_back(src);
    reverse(path.begin(), path.end());
    return path;
}

/* write core logic here */
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    edges.reserve(m);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    vector<int> path = dijkstra_with_path(n, edges, 1, n);
    if (path.empty()) {
        cout << -1 << endl;
    }
    else {
        for (int node : path) cout << node << " ";
        cout << endl;
    }
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}
