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

    int findTheCity(int n, vector<vector<int>>& arr, int dis) {

        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(n, INF));
        
        for (auto& edge : arr) { // Build adjacency matrix
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        for (int i = 0; i < n; i++) dist[i][i] = 0;  // Distance from each node to itself is 0

        for (int via = 0; via < n; via++) { // Floyd–Warshall to compute all-pairs shortest distances
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][via] < INF && dist[via][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                    }
                }
            }
        }
        // Count how many cities are reachable within `dis` distance
        int ansCity = -1, minReachable = n;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= dis) cnt++;
            }
            // If multiple cities have same count, choose one with largest index
            if (cnt <= minReachable) {
                minReachable = cnt;
                ansCity = i;
            }
        }
        return ansCity;
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

