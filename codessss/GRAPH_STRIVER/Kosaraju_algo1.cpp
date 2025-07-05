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

/*
  ------------------------------------------------------
 |                                                    |
 |        Kosaraju’s Algorithm — Step by Step 💡       |
 |                                                    |
  ------------------------------------------------------

 🧠 Purpose: To find all Strongly Connected Components (SCCs)
 📌 Use only on directed graphs!

 ✨ STEPS:

 1️⃣ Do a normal DFS and push nodes onto a stack in the order of finishing time.
     → This gives the order in which nodes finish (like topo sort).

 2️⃣ Reverse the graph (transpose edges).
     → For every edge u → v, make it v → u.

 3️⃣ Do DFS on the reversed graph using the stack order.
     → Each DFS from an unvisited node gives one full SCC.

 4️⃣ Store the nodes of each SCC and return the full list.

 🔁 Time Complexity: O(N + E)
*/

// Step 1: Normal DFS to record finishing times
void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st) {
    vis[node] = 1;
    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            dfs(nbr, adj, vis, st);
        }
    }
    st.push(node);
}

// Step 3: DFS on reversed graph to collect nodes of an SCC
void dfs_collect(int node, vector<vector<int>> &rev_adj, vector<int> &vis, vector<int> &component) {
    vis[node] = 1;
    component.push_back(node);
    for (auto nbr : rev_adj[node]) {
        if (!vis[nbr]) {
            dfs_collect(nbr, rev_adj, vis, component);
        }
    }
}

// Kosaraju’s Algorithm Implementation
vector<vector<int>> kosaraju(vector<vector<int>> &adj) {
    int n = adj.size();

    // Step 1: Topological sort using DFS
    vector<int> vis(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, st);
        }
    }

    // Step 2: Reverse the graph
    vector<vector<int>> rev_adj(n);
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            rev_adj[v].push_back(u);
        }
    }

    // Step 3 & 4: DFS on reversed graph to find and store all SCCs
    vector<int> vis2(n, 0);
    vector<vector<int>> sccs;

    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!vis2[node]) {
            vector<int> component;
            dfs_collect(node, rev_adj, vis2, component);
            sccs.push_back(component); // store current SCC
        }
    }

    return sccs;
}

/* write core logic here */
void solve() {
    // int n, m;
    // cin >> n >> m;
    // vector<vector<int>> adj(n);
    // for (int i = 0; i < m; i++) {
    //     int u, v;
    //     cin >> u >> v;
    //     adj[u].push_back(v); // directed edge
    // }

    // vector<vector<int>> sccs = kosaraju(adj);

    // cout << "Total SCCs: " << sccs.size() << endl;
    // for (int i = 0; i < sccs.size(); i++) {
    //     cout << "SCC #" << i + 1 << ": ";
    //     for (int node : sccs[i]) cout << node << " ";
    //     cout << endl;
    // }
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
    while(t--) {
        solve();
    }
    return 0;
}
