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

/*
🔰 STEPS TO SOLVE:

1️⃣ Negate all edge weights to convert the maximum score path problem into a shortest path problem.

2️⃣ Apply Bellman-Ford Algorithm:
     ➤ Relax all edges for (n - 1) iterations to calculate minimum distances.
     ➤ Perform one more iteration (the nth) to check if any edge still relaxes a node ⇒ negative cycle in negated graph ⇒ positive cycle in original graph.

3️⃣ Maintain an 'affected' array to mark which nodes are part of or reachable from a negative cycle.

4️⃣ If destination node (node n) is affected by a positive cycle, print -1.
    Else, print the negative of the shortest path to node n (i.e., maximum score).
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

/* write core logic here */
void solve() {
    int n, m;
    cin >> n >> m;

    // ➤ Store adjacency list with negated edge weights
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        a--, b--;
        adj[a].push_back({b, -x}); // store with -w to convert max path to min
    }

    // ➤ Initialize distances: INF for all, 0 for source (node 0)
    vector<int> dis(n, 1e18);
    dis[0] = 0;

    // ➤ Relax all edges (n - 1) times
    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (auto ele : adj[u]) {
                int v = ele.first;
                int w = ele.second;
                if (dis[u] != 1e18 && dis[u] + w < dis[v]) {
                    dis[v] = dis[u] + w;
                }
            }
        }
    }

    // ➤ Check for negative cycles in nth iteration
    vector<bool> affected(n, 0); // let no node affected

    for (int i = 0; i < n; i++) {
        for (int u = 0; u < n; u++) {
            for (auto ele : adj[u]) {
                int v = ele.first;
                int w = ele.second;

                // ➤ If any edge can still relax a node in the nth iteration,
                //    it means there's a negative cycle in the negated graph ⇒ positive cycle in the original graph.
                //    We mark this node as affected and update its distance to -INF.
                if (dis[u] != 1e18 && dis[u] + w < dis[v]) {
                    dis[v] = -1e18;
                    affected[v] = true;
                }

                // ➤ Even if v was not directly relaxed in the nth iteration,
                //    if u is already affected, and there's an edge u → v,
                //    then v is also indirectly affected (because we can reach it from a cycle).
                if (affected[u]) {
                    affected[v] = true;
                }
            }
        }
    }

    // ➤ Final output
    if (affected[n - 1]) {
        cout << -1 << endl;
    } else {
        cout << -dis[n - 1] << endl; // un-negate final result to get maxm value 
    }
}
/* logic ends */

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    int t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
