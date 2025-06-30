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

/// TOPOLOGICAL SORT using DFS
void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
    vis[node] = 1;
    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            dfs(nbr, adj, vis, st);
        }
    }
    st.push(node); // push after visiting all neighbors
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
        adj[u].push_back(v); // directed edge
    }

    // Step 1: Topological Sort
    vector<int> vis(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, st);
        }
    }

    // Step 2: Longest Path DP
    vector<int> dp(n, -1);      // dp[i] = max nodes on path from 0 to i
    vector<int> par(n, -1);     // par[i] = parent of i in longest path
    dp[0] = 1; // start from node 0 (city 1)

    /*
        ---- DP + Toposort Explanation ----
        In DAG, longest path can be found in topological order by relaxing edges.

        dp[node] = max nodes on path from source to this node.

        For each node in topo order:
            for each nbr:
                if dp[nbr] < dp[node] + 1:
                    update dp[nbr] = dp[node] + 1
                    update parent[nbr] = node

        This works like Bellman-Ford, but in 1 pass using topo order.

        Example:
            Input:
            1 -> 2
            1 -> 3
            3 -> 4
            4 -> 5
            2 -> 5

            Longest path from 1 to 5 is 1 -> 3 -> 4 -> 5
            dp[0]=1
            dp[2]=dp[0]+1=2
            dp[3]=dp[0]+1=2
            dp[4]=dp[3]+1=3
            dp[1]=dp[0]+1=2
            dp[4]=max(dp[4], dp[1]+1)=max(3,3)=3
            dp[5]=dp[4]+1=4
    */

    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (dp[node] == -1) continue; // no path from 0 to this node
        for (auto nbr : adj[node]) {
            if (dp[nbr] < dp[node] + 1) {
                dp[nbr] = dp[node] + 1;
                par[nbr] = node;
            }
        }
    }

    if (dp[n - 1] == -1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    // Step 3: Reconstruct Path
    vector<int> path;
    int cur = n - 1;
    while (cur != -1) {
        path.push_back(cur);
        cur = par[cur];
    }
    reverse(path.begin(), path.end());

    cout << path.size() << endl;
    for (auto city : path) {
        cout << city + 1 << " "; // convert to 1-based
    }
    cout << endl;
}
/* logic ends */

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    //cin>>t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
