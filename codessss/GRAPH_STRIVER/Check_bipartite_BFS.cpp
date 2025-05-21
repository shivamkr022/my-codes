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

    // BFS function to check bipartiteness from a given start node

    bool check_Bipartite_BFS(int start, vector<vector<int>> &adj , vector<int>& color) {
        
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto nbr : adj[node]) {
                if (color[nbr] == -1) {
                    color[nbr] = !color[node];  // alternate color
                    q.push(nbr);
                }
                else if (color[nbr] == color[node]) {
                    return false;  // same color for adjacent nodes
                }
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
            adj[v].push_back(u);  // undirected graph
        }

        vector<int> color(V, -1); // init mark all -1 

        for (int i = 0; i < V; i++) { // visit all bec can be diff comp here
            if (color[i] == -1) {
                if (!check_Bipartite_BFS(i, adj, color)) {
                    return false;
                }
            }
        }

        return true;
    }
/* write core logic here */
void solve(){

    ///------>> INPUT
    
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

