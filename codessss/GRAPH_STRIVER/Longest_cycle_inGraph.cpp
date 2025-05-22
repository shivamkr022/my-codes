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

    int lc = -1;
    void dfs(int node, vector<int> &edges, vector<int> &vis, vector<int> &pathvis, vector<int> &et, int depth) {
        vis[node] = 1;
        pathvis[node] = 1;
        et[node] = depth;
        int nbr = edges[node];
        if (nbr != -1) {
            if (!vis[nbr]) {
                dfs(nbr, edges, vis, pathvis, et, depth + 1);
            }
            else if (pathvis[nbr]) {
                lc = max(lc, depth - et[nbr] + 1); // cycle found
            }
        }
        pathvis[node] = 0; // backtrack
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n, 0), pathvis(n, 0), entryTime(n, -1);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, edges, vis, pathvis, entryTime, 0);
            }
        }
        return lc;
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

