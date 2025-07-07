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

class Solution {
    
private:
    int timer = 1;

    void dfs(int node, int parent, vector<vector<int>> &adj,
             vector<int> &vis, vector<int> &ins_time,
             vector<int> &lowest_ins_time, vector<vector<int>> &bridges) {

        vis[node] = 1;
        ins_time[node] = lowest_ins_time[node] = timer++;
        
        for (auto nbr : adj[node]) {
            if (nbr == parent) continue;  // Skip the parent node
            
            if (!vis[nbr]) {
                
                dfs(nbr, node, adj, vis, ins_time, lowest_ins_time, bridges);
                
                // Update lowest insertion time
                lowest_ins_time[node] = min(lowest_ins_time[node], lowest_ins_time[nbr]);
                
                // Bridge condition
                if (lowest_ins_time[nbr] > ins_time[node]) {
                    bridges.push_back({node, nbr});
                }
            }
            else {
                // Back edge
                lowest_ins_time[node] = min(lowest_ins_time[node], ins_time[nbr]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        vector<int> ins_time(n, 0); // insertion time 
         // just dont calculate the insertion time of the parents // skip the praents
        vector<int> lowest_ins_time(n, 0);  // lowest insertion time 
        vector<vector<int>> bridges;  // answer

        dfs(0, -1, adj, vis, ins_time, lowest_ins_time, bridges);

        return bridges;
    }
};

/* write core logic here */
void solve(){
    // input
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

