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

void dfs(int node , vector<vector<int>>&adj , vector<int>&vis ){  // normal dfs
    vis[node] = 1;
    for(auto nbr : adj[node]){
        if(!vis[nbr]){
            dfs(nbr , adj , vis) ;
        }
    }
}

/* write core logic here */
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;             /// adj list 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>vis(n,0);
    int ans = 0;
    vector<int>path;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            ans++;
            path.push_back(i);
            dfs(i,adj,vis);
        }
    }
    if(path.size()==1){
        cout<<0<<endl;
        return ;
    }
    cout<<ans-1<<endl;
    for(int i=0;i<path.size()-1;i++){
        cout<<path[i]<<" "<<path[i+1]<<" " <<endl;
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

