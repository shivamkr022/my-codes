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

    // Helper function to perform DFS and color nodes
    bool check_bipartite_DFS(int node, vector<vector<int>> &adj, vector<int> &color) {
        for (int nbr : adj[node]) {
            if (color[nbr] == -1) {   // it means its not visited
                color[nbr] = !color[node]; // Assign opposite color
                if (!check_bipartite_DFS(nbr, adj, color)) {
                    return false;
                }
            }
            else if (color[nbr] == color[node]) {
                return false; // Adjacent node has same color → not bipartite
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // Undirected graph
        }
        
        vector<int> color(V, -1);        // Step 2: Initialize color array with -1 (unvisited)
        // Step 3: Check all connected components
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                color[i] = 0; // Start coloring this component
                if (!check_bipartite_DFS(i, adj, color)) {
                    return false;
                }
            }
        }
        return true;
    }
/* write core logic here */
void solve(){

    ///----->> INPUT
    
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

