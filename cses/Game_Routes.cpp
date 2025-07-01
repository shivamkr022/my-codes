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

// Topo sort
void dfs_topo(int node ,  vector<vector<int>> &adj ,vector<int> &vis , stack<int> &st){
    vis[node] = 1;
    for(auto nbr : adj[node]){
        if(!vis[nbr]){
            dfs_topo(nbr , adj , vis ,st);
        }
    }
    st.push(node);
}

/* write core logic here */
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int>vis(n,0);
    stack<int>st;

    for(int i=1 ;i<=n;i++){
        if(!vis[i]){
            dfs_topo(i ,adj, vis,st);
        }
    }

    vector<int> dp(n+1,0);
    dp[1] = 1;  //stores the number of ways to reach node i from node 1 // here 1 to 1 so 1 way

     while(!st.empty()){
        int u = st.top();
        st.pop();
        for(auto v : adj[u]){
            dp[v] = (dp[u] + dp[v]) % mod ;
       // dp[u]: number of ways to reach u from node 1
       // dp[v]: number of ways already calculated to reach v from other paths
       // You’re adding dp[u] to dp[v] because:
       // Every way to reach u gives rise to a new way to reach v via the edge u → v
        }
     }
     cout << dp[n] << endl;
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

