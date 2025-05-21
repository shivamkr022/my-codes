/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Shivam           |
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

#define endl "\n"
#define int long long

vector<vector<int>> adj;
vector<int> countColor(2, 0);

// DFS to color and count nodes in two sets
void dfs(int node, int color, int parent = -1) {
    countColor[color]++;
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            dfs(neighbor, 1 - color, node);
        }
    }
}
int solve(int n, vector<pair<int, int>>& edges) {
    adj.assign(n + 1, vector<int>());

    for (auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0); // Start DFS from node 1

    return countColor[0] * countColor[1] - (n - 1);
}

// Main driver function
void run() {
    int n;
    cin >> n;
    vector<pair<int, int>> edges(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }
    cout << solve(n, edges) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif

    int t = 1;
    // cin >> t;
    while (t--) {
        run();
    }

    return 0;
}
