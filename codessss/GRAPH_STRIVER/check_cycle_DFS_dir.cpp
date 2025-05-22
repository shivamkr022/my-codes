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

bool check_cycle_DFS_dir(int node, vector<vector<int>> &adj, vector<int>& vis, vector<int>& pathvis) {
      vis[node] = 1;
      pathvis[node] = 1;

      for (auto nbr : adj[node]) {
          if (!vis[nbr]) {
              if (check_cycle_DFS_dir(nbr, adj, vis, pathvis)) {
                  return true; // Cycle detected
              }
          }
          else if (pathvis[nbr]) {
              return true; // Back edge found, cycle exists
          }
      }

      pathvis[node] = 0; // Backtrack
      return false;
  }

  bool isCyclic(int n, vector<vector<int>> &edges) {
      vector<vector<int>> adj(n);
      for (auto & ele : edges) {
          int u = ele[0];
          int v = ele[1];
          adj[u].push_back(v);  // Directed edge: u → v
      }

      vector<int> vis(n, 0), pathvis(n, 0);
      for (int i = 0; i < n; i++) {
          if (!vis[i]) {
              if (check_cycle_DFS_dir(i, adj, vis, pathvis)) {
                  return true;
              }
          }
      }

      return false;
  }

/* write core logic here */
void solve(){

    /// ----->> INPUT
    
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

