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

void rec_dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& ans) { 
    vis[node] = 1;   /// recursive call for DFS travesral
    ans.push_back(node); // node here is starting node
    for (auto curr_node : adj[node]) {
        if (!vis[curr_node]) {
            rec_dfs(curr_node, adj, vis, ans); // recusrsive call for each node
        }
    }
}
// Main DFS function that initializes the visited array
// and call Rec_dfs

vector<int> dfs(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int>vis(n,0);
    int start =0;
    vector<int>ans; // to store each node
    rec_dfs(start,adj,vis,ans);
    return ans;

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

