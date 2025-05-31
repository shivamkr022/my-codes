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

    void paths(int node , vector<vector<int>>& adj , vector<vector<int>>&all_paths , vector<int>&curr_path){
        int n = adj.size();
        curr_path.push_back(node);
        if(node == n-1){
            all_paths.push_back(curr_path);  // one path found
        }
        else{
            for (auto nbr : adj[node]){
                paths(nbr,adj,all_paths,curr_path);  // dfs traversal
            }
        }
        curr_path.pop_back();  // backtrack -> as soon as we got a path it removes last added node and check for nbr and if not it removes sec last node and so on
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<vector<int>>all_paths;
        vector<int>curr_path;
        paths(0,adj,all_paths,curr_path); // source node will always be zero
        return all_paths ; //answer 
    }

/* write core logic here */
void solve(){

    /// ---- >> INPUT 
    
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

