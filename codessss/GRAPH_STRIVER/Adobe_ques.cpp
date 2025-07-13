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
#define int long long
#define mod 1000000007
#define mn(a,b,c) min(a, min(b, c))
#define mx(a,b,c) max(a, max(b, c))
using namespace std;

void tarjan(int node, int par, vector<vector<int>> &adj, vector<int> &vis,
            vector<int> &min_time, vector<int> &low_in_time, int &timer, vector<int> &ans) {
    
    vis[node] = 1;
    min_time[node] = low_in_time[node] = timer++;
    int child_count = 0;

    for (int nbr : adj[node]) {
        if (nbr == par) continue;

        if (!vis[nbr]) {
            tarjan(nbr, node, adj, vis, min_time, low_in_time, timer, ans);
            low_in_time[node] = min(low_in_time[node], low_in_time[nbr]);

            // Check if it's an articulation point
            if (par != -1 && low_in_time[nbr] >= min_time[node]) {
                ans[node] = 1;
            }
            child_count++;
        }
        else {
            // Back edge
            low_in_time[node] = min(low_in_time[node], min_time[nbr]);
        }
    }

    // Root special case
    if (par == -1 && child_count > 1) {
        ans[node] = 1;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // 0-based input — no decrement needed
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> vis(n, 0), min_time(n, 0), low_in_time(n, 0), ans(n, 0);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            tarjan(i, -1, adj, vis, min_time, low_in_time, timer, ans);
        }
    }

    for (int i = 0; i < n; i++) {
        if (ans[i]) cout << i << endl ;
    }

}

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
