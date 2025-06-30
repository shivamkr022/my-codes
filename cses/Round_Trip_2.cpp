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
#ifndef ONLINE_JUDGE
#define debug(x) cout << "errr---- " << #x << " " << x << endl
#define print(v) do { \
    cout << "vect--" << #v << " = [ "; \
    for (int i = 0; i < v.size(); i++) cout << v[i] << " "; \
    cout << " ]" << endl; \
} while(0)
#else
#define debug(x)
#define print(v)
#endif

#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a, b, c) min(a, min(b, c))
#define mx(a, b, c) max(a, max(b, c))
using namespace std;

// Function to detect a cycle in a directed graph using DFS
bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& parent, int& cycleStart, int& cycleEnd) {
    vis[node] = 1;  // 1 = currently visiting
    for (int neighbor : adj[node]) {
        if (vis[neighbor] == 0) {
            parent[neighbor] = node;
            if (dfs(neighbor, adj, vis, parent, cycleStart, cycleEnd))
                return true;
        } else if (vis[neighbor] == 1) {
            // Found a back edge => cycle
            cycleStart = neighbor;
            cycleEnd = node;
            return true;
        }
    }
    vis[node] = 2;  // 2 = fully visited
    return false;
}

/* write core logic here */
void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--; // 0-based indexing
        adj[u].push_back(v);
    }

    vector<int> vis(n, 0), parent(n, -1);
    int cycleStart = -1, cycleEnd = -1;

    for (int i = 0; i < n; i++) {
        if (vis[i] == 0) {
            if (dfs(i, adj, vis, parent, cycleStart, cycleEnd)) {
                break;
            }
        }
    }

    if (cycleStart == -1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    // Reconstruct the cycle path
    vector<int> cycle;
    cycle.push_back(cycleStart);
    for (int v = cycleEnd; v != cycleStart; v = parent[v]) {
        cycle.push_back(v);
    }
    cycle.push_back(cycleStart);
    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << endl;
    for (int node : cycle) {
        cout << node + 1 << " ";  // Convert back to 1-based
    }
    cout << endl;
}
/* logic ends */

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    int t;
    //cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
