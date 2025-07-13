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

/*
    -------------------- Floyd–Warshall Algorithm --------------------
    Goal: Find the shortest distance between every pair of nodes.
    ------------------------------------------------------------------
    Step 1: Initialize the distance matrix:
        - dist[i][j] = weight of edge from i to j
        - If no edge exists between i and j, set dist[i][j] = ∞
        - dist[i][i] = 0 for all i (distance to self is zero)
    ------------------------------------------------------------------
    Step 2: Run the main loop:
        for each intermediate node via = 0 to n-1:
            for each source node i = 0 to n-1:
                for each destination node j = 0 to n-1:
                    - Check if going through 'via' gives a shorter path:
                        dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j])
                    - Means: can we go from i to j more efficiently through via?

    ------------------------------------------------------------------
    Step 3: Optional - Detect negative weight cycles:
        - If dist[i][i] < 0 for any node i, then a negative weight cycle exists

    ------------------------------------------------------------------
    Properties:
        - Handles negative weights ✔
        - Detects negative cycles ✔
        - All-pairs shortest path ✔
        - Time Complexity: O(n^3)
        - Space Complexity: O(n^2)
    ------------------------------------------------------------------
    Note: Works for both directed and undirected graphs.
*/

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
 // Step 2: Detect negative cycles
    for (int i = 0; i < n; ++i) {
        if (dist[i][i] < 0) {
            cout << "Negative weight cycle detected involving node " << i << endl;
            // Optional: handle it (e.g., stop, return a flag, etc.)
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

