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

/* write core logic here */
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
    vector<int>vis(n+1,0);
    pq.push({0,1}) ; // {wt,node}
    int sum = 0;
    
    while(!pq.empty()){
        auto ele = pq.top();
        pq.pop();
        int curr_wt = ele.first;
        int curr_node = ele.second;
        if(vis[curr_node]==1) continue;
        // not visited ->
        vis[curr_node] = 1;
        sum += curr_wt ;

        for(auto nbr : adj[curr_node]){
            int adj_node = nbr.first;
            int edg_wt = nbr.second;

            if(!vis[adj_node]){
                pq.push({edg_wt,adj_node});
            }
        }
    }
    bool ok = true ;
    for(int i = 1; i <=n; i++){
        if(vis[i] == 0){
            ok = false;
            break;
        }
    }
    if(ok) cout<<sum<<endl ;  // returns total weight of MST
    else cout<<"IMPOSSIBLE"<<endl;
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

