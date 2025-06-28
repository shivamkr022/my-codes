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

bool bipartite(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &col, int c) {
    vis[node] = 1;
    col[node] = c;

    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            if (!bipartite(nbr, adj, vis, col, 1-c)) {
                return false;
            }
        }
        else if (col[nbr] == col[node]) {
            return false;
        }
    }
    return true;
}

/* write core logic here */
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>vis(n,0);
    vector<int>col(n,0);

    bool ok = true ;

    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(!bipartite(i,adj,vis,col,0)){
                ok = false;
                break;
            }
        }
    }
    if(ok){
    for(int i=0;i<n;i++){
        cout<<col[i]+1<<" ";
    }
    cout<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }

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

