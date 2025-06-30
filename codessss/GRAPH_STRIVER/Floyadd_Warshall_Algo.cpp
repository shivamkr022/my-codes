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

void floydWarshall(vector<vector<int>> &dist) {

    int n = dist.size();           // Number of nodes
    const int INF = 1e8;           // Representation of no connection (infinity)
    /*
        Floyd-Warshall Algorithm: All Pairs Shortest Path

        Step 1: Iterate over each node as an intermediate node ('via')
        Step 2: For every pair (i, j), check if going through 'via' offers a shorter path

        Core Condition to update dist[i][j]:
            - If dist[i][via] != INF (i to via is reachable)
            - AND dist[via][j] != INF (via to j is reachable)
            - THEN: it's safe to update dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j])
    */

    for (int via = 0; via < n; via++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                // ✅ Condition to ensure safe addition and avoid INF overflow
                if (dist[i][via] != INF && dist[via][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }

            }
        }
    }

    /*
        Optional Step:
        If you want to return the result with -1 for unreachable pairs,
        instead of INF, you can replace them now.
    */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) {
                dist[i][j] = -1;  // No path from i to j
            }
        }
    }
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

