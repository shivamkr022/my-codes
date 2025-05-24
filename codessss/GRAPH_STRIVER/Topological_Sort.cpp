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

/// TOPOLOGICAL SORT
  void dfs(int node ,vector<vector<int>>&adj,vector<int>&vis,stack<int>&st){
      vis[node]=1;
      for(auto nbr : adj[node]){
          if(!vis[nbr]){
            dfs(nbr,adj,vis,st);  // call dfs
          }
      }
      st.push(node);   // if its get visited just push to stack
  }
    vector<int> topoSort(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto ele : edges){    /// Adjacency List
            int u = ele[0];
            int v = ele[1];      /// durected graph
            adj[u].push_back(v);
        }
        vector<int>vis(n,0);
        stack<int>st;
        for(int i=0;i<n;i++){  // start from node 0->N
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        vector<int>ans;
        while(!st.empty()){  // storing ans in vector
            ans.push_back(st.top());
            st.pop();
        }
        return ans ;
    }

/* write core logic here */
void solve(){

    // --->> INPUT
    
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

