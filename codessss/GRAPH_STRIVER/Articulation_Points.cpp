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
    -------- Tarjan's Algorithm for Articulation Points --------

    ✅ What is an articulation point?
        - A node is an articulation point if removing it increases the number of connected components.

    ✅ Use Case:
        - To find critical routers, cut points, failure points in a network, etc.

    ✅ Steps:
        1. Build adjacency list from edges.
        2. Run DFS and maintain:
           - `in_time[]`: the time when a node is first visited.
           - `low_time[]`: the lowest in_time reachable from the subtree rooted at that node.
        3. For a node u and its child v:
            - If `low[v] >= in[u]`, then u is an articulation point (if u is not root).
        4. For root, if it has more than one child, it is also an articulation point.

    ✅ Time Complexity: O(V + E)

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

int timer = 0;

// Core DFS logic to find articulation points using Tarjan’s algorithm
void dfs(int node ,int par ,vector<vector<int>>&adj ,vector<int> &in_time,
         vector<int> &low_time , vector<int> &mark ,vector<int> &vis){

    vis[node] = 1;
    in_time[node] = low_time[node] = timer++;
    int child = 0;

    for(auto nbr : adj[node]){
        if(nbr == par) continue; // ignore parent edge

        if(!vis[nbr]){
            dfs(nbr , node , adj , in_time , low_time , mark , vis);
            low_time[node] = min(low_time[node], low_time[nbr]);

            // Articulation condition (except root)
            if(low_time[nbr] >= in_time[node] && par != -1){
                mark[node] = 1;
            }
            child++;
        }
        else{
            // Back edge
            low_time[node] = min(low_time[node], in_time[nbr]);
        }
    }

    // Special case for root node
    if(par == -1 && child > 1){
        mark[node] = 1;
    }
}

// Finds all articulation points in the graph
vector<int> articulationPoints(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    for(auto &e : edges){
        int u = e[0], v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    vector<int> in_time(n, 0), low_time(n, 0);
    vector<int> mark(n, 0), vis(n, 0);

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i, -1, adj, in_time, low_time, mark, vis);
        }
    }

    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(mark[i]) ans.push_back(i);
    }

    if(ans.empty()) return {-1};
    return ans;
}

/* Write core logic here */
void solve(){
    /*
        Example Graph:
        7 nodes, edges:
        0-1, 0-2, 1-2, 2-3, 3-4, 3-5, 4-6

        Expected articulation points: [2, 3, 4]
    */

    int n = 7;
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {1, 2}, {2, 3}, {3, 4}, {3, 5}, {4, 6}
    };

    vector<int> result = articulationPoints(n, edges);

    cout << "Articulation Points: ";
    for(int x : result) cout << x << " ";
    cout << endl;
}
/*
    Example to understand:
        0
       / \
      1---2
           \
            3
             \
              4

    Edges: [0-1], [0-2], [1-2], [2-3], [3-4]

    DFS starts at node 0.
    - in_time[2] = 2, low[3] = 3, so low[3] >= in_time[2]
    - That means there's no back-edge from subtree rooted at 3 going above 2.

    So, node 2 is an articulation point. Removing node 2 disconnects node 3 and 4.

    That’s why: 
        if (low_time[nbr] >= in_time[node] && par != -1)
        => node is a critical connector for that subtree.
*/

/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
