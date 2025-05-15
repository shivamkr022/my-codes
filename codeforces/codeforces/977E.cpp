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
#define debug(x) cout << "errr----  " << #x << " " << x << endl 
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

// cycle component detection

bool detectCycleBFS(int src, vector<vector<int>>& adj, vector<int>& vis) {
    queue<int> q;
    vis[src] = 1;
    q.push(src);

    bool isCycle = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (adj[node].size() != 2) {  // must have two nbr exactly
            isCycle = false;
        }
        for (int nbr : adj[node]) {
            if (!vis[nbr]) {
                vis[nbr] = 1;
                q.push(nbr);
            }
        }
    }
    return isCycle;
}

/* Core logic */
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);  // 1-based indexing
    vector<int> vis(n + 1, 0);
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Undirected graph
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (detectCycleBFS(i, adj, vis)) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}

/* Main */
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
