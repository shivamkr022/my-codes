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

int findCheapestPrice(int n, vector<vector<int>>& arr, int src, int dst, int k) {

        vector<pair<int,int>>adj[n];
        for(auto ele : arr){
            int u = ele[0];
            int v = ele[1];
            int w = ele[2];
            adj[u].push_back({v,w});  // Directed Graph 
        }
       // use queue bcoz we are priorisinf stops and that ic by one i.e cons increment
       // thats bcoz we keep first stop not price 
       
        queue<pair<int,pair<int,int>>> q; // ({stops,{curr_node , price}})
        vector<int>dis(n,1e9);
        q.push({0,{src,0}});
        dis[src] = 0;
        
        while(!q.empty()){
            auto ele = q.front();
            q.pop();
            int stops = ele.first;
            int curr_node = ele.second.first;
            int curr_price = ele.second.second;

            if(stops > k) continue ;

            for (auto nbr : adj[curr_node]){
                int edg_wt = nbr.second;
                int adj_node = nbr.first;
                if(edg_wt + curr_price < dis[adj_node] and k >= stops){
                    dis[adj_node] = edg_wt + curr_price ;
                    q.push({stops+1,{adj_node,edg_wt + curr_price}});
                }
            }
        }
        if(dis[dst] == 1e9) return -1;
        return dis[dst];
    }

/* write core logic here */
void solve(){

    // INPUT 
    
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

