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
    🔁 Bellman-Ford Algorithm 🔁

    ✅ Usage:
        - Single source shortest path
        - Works with **negative weight edges**
        - Can detect **negative weight cycles**

    ⚠️ Conditions:
        - Works on directed or undirected graphs
        - Time Complexity: O(n * m) → slow for large n
        - Use when:
            - Graph has negative edges
            - You want to detect negative cycles
            - Graph is sparse (m not too large)
        - Don't use if:
            - All weights are positive → prefer Dijkstra
            - Graph is large and dense (n > ~5000)

    🧠 Logic:
        1. Initialize all distances as INF except src = 0
        2. Relax all edges (n-1) times
        3. If in the nth iteration, any edge can be relaxed → negative cycle exists
*/

vector<int> bellmanFord(int n, vector<vector<int>>& edges, int src) {
    
    vector<int>dis(n, 1e8); // distance array
    dis[src] = 0 ;

    // n-1 relaxation // in n-1 relaxation all node get its value
    for (int i = 0; i < n - 1; i++) {  // n-1th relaxation done
        for (auto ele : edges) {
            int u = ele[0];
            int v = ele[1];
            int w = ele[2];

            // Relax edge if shorter path is found
            if (dis[u] != 1e8 and dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
            }
        }
    }

    // to check the negative cycle exist or not
    // if neg cycle exist then it update the value in nth relaxation too 
    // nth relaxation
    for (auto ele : edges) {
        int u = ele[0];
        int v = ele[1];
        int w = ele[2];

        if (dis[u] != 1e8 and dis[u] + w < dis[v]) { // got updated value means neg cycle exists
            return {-1} ;
        }
    }

    return dis ;
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

