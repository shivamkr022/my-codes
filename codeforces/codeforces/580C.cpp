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

int ans = 0;
void dfs(int st, int par, int count, vector<int>& arr, vector<vector<int>>& adj, int m){
    if(arr[st] == 1) count++;
    else count = 0;
    if(count > m) return;
    if (adj[st].size() == 1 && st != 1){
        ans++;
    }
    for(auto ele : adj[st]){
        if (ele == par) continue;
        dfs(ele, st, count, arr, adj, m);
    }
}
/* write core logic here */
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;                  /// creating adjacency list
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    dfs(1, 0, 0, arr, adj, m);
    cout << ans << endl;
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

