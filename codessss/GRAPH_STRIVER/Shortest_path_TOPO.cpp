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

// Normal Toposort

    void toposort(int node, vector<vector<pair<int,int>>> &adj, vector<int> &vis, stack<int> &st){
        vis[node] = 1;
        for (auto nbr : adj[node]) {
            int v = nbr.first;
            if (!vis[v]) {
                toposort(v, adj, vis, st);
            }
        }
        st.push(node); // fixed: `stack.push(node)` → `st.push(node)`
    }

    vector<int> shortestPath(int n, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for (int i = 0; i < E; i++) {
            int u = edges[i][0];        // Create adjacency list: adj[u] = {v, wt}
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        vector<int> vis(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                toposort(i, adj, vis, st);        // 1. Topological Sort
            }
        }

        vector<int> dist(n, 1e9);
        dist[0] = 0; // Assuming 0 is the source node
        while (!st.empty()) {  // 3. Relax edges in topological order
            int node = st.top();
            st.pop();
            if (dist[node] != 1e9) {
                for (auto it : adj[node]) {
                    int v = it.first;
                    int w = it.second;
                    if (dist[node] + w < dist[v]) {
                        dist[v] = dist[node] + w;
                    }
                }
            }
        }
        
        for (int i = 0; i < n; i++) { /// convert unreachable distances to -1
            if (dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
    }

/* write core logic here */
void solve(){
    
    //----->>> INPUT
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

