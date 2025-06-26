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

/*
🔷 STEPS FOR SHORTEST PATH (1 to n) USING DIJKSTRA’S ALGORITHM WITH PATH RECOVERY 🔷

1️⃣ Input and Graph Construction:
    - Read number of nodes `n` and edges `m`.
    - Read all `m` edges: each with format (u, v, w).
    - Build the graph as an undirected adjacency list:
        - `adj[u]` stores a list of pairs: {v, weight}.
        - Since undirected, also store `adj[v].push_back({u, w})`.

2️⃣ Initialize:
    - Distance array `dis[n+1]`:
        - Set all distances to a large value (1e18).
        - `dis[1] = 0`, since we start from node `1`.

    - Parent array `par[n+1]`:
        - `par[i] = i` initially; used to reconstruct the path.

    - Min-heap priority queue `pq`:
        - Each element is a pair: {distance_so_far, node}.
        - Start with `{0, 1}` since source node is `1`.

3️⃣ Dijkstra’s Loop:
    - While `pq` is not empty:
        a) Extract the top element from `pq` → `(curr_dis, curr_node)`.
        b) If `curr_dis > dis[curr_node]`, continue (skip outdated entry).
        c) Traverse all adjacent nodes of `curr_node`:
            i)   For neighbor `adj_node` and edge weight `edge_wt`,
            ii)  If `dis[adj_node] > curr_dis + edge_wt`:
                    - Update: `dis[adj_node] = curr_dis + edge_wt`
                    - Push `{dis[adj_node], adj_node}` into the PQ.
                    - Update parent: `par[adj_node] = curr_node`

4️⃣ Check for Reachability:
    - If `dis[n] == INF (1e18)`, there’s no path from node 1 to node n → return `{-1}`.

5️⃣ Reconstruct Path:
    - Start from node `n`, follow parent pointers backwards using `par[]`.
    - Push each node into `path[]` while going back.
    - Stop when `node == par[node]` (starting node reached).
    - Reverse the path to get order from 1 → n.

6️⃣ Return:
    - Return the `path[]` vector containing the shortest path from 1 to n.

⏱️ Time Complexity:
    - O((E + V) * logV)
        - V: Number of vertices (nodes)
        - E: Number of edges
        - logV: Due to priority queue operations

✅ Best used with sparse graphs.
✅ This version also **recovers the actual path**, not just distance.
*/


// Print shortest Path from src to des ---- >>>>>>

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {

    vector<vector<pair<int,int>>> adj(n + 1); 

    for(auto& edge : edges){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dis(n + 1, 1e18);
    vector<int> par(n + 1);

    for(int i = 1; i <= n; i++) par[i] = i;

    dis[1] = 0;
    pq.push({0, 1});

    while(!pq.empty()) {
        auto it = pq.top(); // it is of type pair<int, int>
        pq.pop();
        int curr_dis = it.first;
        int curr_node = it.second;

        if (curr_dis > dis[curr_node]) continue;

        for(auto& nbr : adj[curr_node]){
            int adj_node = nbr.first;
            int edge_wt = nbr.second;

            if(curr_dis + edge_wt < dis[adj_node]){
                dis[adj_node] = curr_dis + edge_wt;
                pq.push({dis[adj_node], adj_node});
                par[adj_node] = curr_node;
            }
        }
    }

    if(dis[n] == 1e18) return {-1};  // no path

    vector<int> path;
    int node = n;
    while (node != par[node]) {
        path.push_back(node);
        node = par[node];
    }
    path.push_back(node);
    reverse(path.begin(), path.end());

    return path;
}

/* write core logic here */
void solve(){
    // int n, m;
    // cin >> n >> m;
    // vector<vector<int>> edges;

    // for (int i = 0; i < m; i++) {
    //     int u, v, w;
    //     cin >> u >> v >> w;            // INPUT
    //     edges.push_back({u, v, w});
    // }

    // vector<int> path = shortestPath(n, m, edges);
    // if (path.size() == 1 && path[0] == -1) {
    //     cout << -1 << endl;
    // }
    // else {
    //     for (int node : path) cout << node << " ";
    //     cout << endl;
    // }
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}
