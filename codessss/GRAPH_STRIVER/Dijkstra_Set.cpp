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


vector<vector<vector<int>>> constructAdj(vector<vector<int>> &edges, int V){
    
    // adj[u] = list of {v, wt}
    vector<vector<vector<int>>> adj(V); 
    for (const auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt}); 
    }
    return adj;
}

// Returns shortest distances from src to all other vertices
vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
    vector<vector<vector<int>>> adj = constructAdj(edges, V);

    // Set to store {distance, node}
    set<pair<int, int>> st;

    vector<int> dist(V, INT_MAX);

    dist[src] = 0;
    st.insert({0, src});

    while (!st.empty()) {
        auto it = *(st.begin());
        int u = it.second;
        
        // Remove the node with the smallest distance
        st.erase(it); 

        for (auto x : adj[u]) {
            int v = x[0];
            int weight = x[1];

            // If shorter path found
            if (dist[v] > dist[u] + weight) {
                
                // If v already in set, erase the older (larger dist) entry
                if (dist[v] != INT_MAX) {
                    st.erase({dist[v], v});
                }
                dist[v] = dist[u] + weight;
                st.insert({dist[v], v});
            }
        }
    }
    return dist;
}

/* write core logic here */
void solve(){
    
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

