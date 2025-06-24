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

    bool dfs_detect_cycle(int node,int par_node,vector<vector<int>>& arr,vector<int>&vis){
        
        vis[node] = 1;
        for(auto nbr_node : arr[node]){
            if(!vis[nbr_node]){
               if(dfs_detect_cycle(nbr_node,node,arr,vis)==true){ // here node became PN 
                   return true;
               } 
            }
            else if(nbr_node!= par_node){  // its visted but not a parent node means cycle;
                return true;
            }
        }
        return false ;
    }
    
/* write core logic here */
void solve(){
    //------>>> INPUT:
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

