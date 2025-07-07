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
// User function Template for C++

class Solution {
    
private:
    int timer = 1;

    // Tarjan's Algorithm to find Bridges in an Undirected Graph
    // ---------------------------------------------------------
    // A bridge (or critical connection) is an edge that, if removed, will increase
    // the number of connected components of the graph.
    //
    // Condition to Use:
    // Use Tarjan’s algorithm when you need to find bridges or articulation points
    // in a connected undirected graph in O(N + M) time using DFS.
    //
    // Main Idea:
    // For each node, we keep track of:
    //   - ins_time[node]: The time when the node was first visited
    //   - lowest_ins_time[node]: The lowest time that can be reached from this node (via DFS/back edges)
    // If for a neighbor nbr:
    //    lowest_ins_time[nbr] > ins_time[node], then (node, nbr) is a bridge.

    void dfs(int node, int parent, vector<vector<int>> &adj,
             vector<int> &vis, vector<int> &ins_time,
             vector<int> &lowest_ins_time, vector<vector<int>> &bridges) {

        vis[node] = 1;
        ins_time[node] = lowest_ins_time[node] = timer++;

        for (auto nbr : adj[node]) {
            if (nbr == parent) continue;  // Skip the parent

            if (!vis[nbr]) {
                // Explore unvisited child
                dfs(nbr, node, adj, vis, ins_time, lowest_ins_time, bridges);

                // Update the lowest reachable time after returning from recursion
                lowest_ins_time[node] = min(lowest_ins_time[node], lowest_ins_time[nbr]);

                // Check bridge condition
                if (lowest_ins_time[nbr] > ins_time[node]) {
                    bridges.push_back({node, nbr});
                }

            } else {
                // If already visited and not parent, it's a back edge
                lowest_ins_time[node] = min(lowest_ins_time[node], ins_time[nbr]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
        // -------------------------------------------
        // Step-by-Step Plan:
        // 1. Build the adjacency list for the graph
        // 2. Initialize:
        //     - vis[n] = visited array
        //     - ins_time[n] = stores time when node is visited
        //     - lowest_ins_time[n] = lowest reachable ins_time from node
        //     - bridges = store the bridge edges
        // 3. Run Tarjan’s DFS from node 0 (assuming graph is connected)
        // 4. Return the list of bridges found
        // -------------------------------------------

        vector<vector<int>> adj(n);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);  // Since graph is undirected
        }

        vector<int> vis(n, 0);
        vector<int> ins_time(n, 0);
        vector<int> lowest_ins_time(n, 0);
        vector<vector<int>> bridges;

        dfs(0, -1, adj, vis, ins_time, lowest_ins_time, bridges);

        return bridges;
    }
};

/* write core logic here */
void solve(){
    
    // INPUT
    
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

