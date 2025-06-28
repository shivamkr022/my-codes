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
🔷 STEPS FOR DIJKSTRA + COUNT PATHS 🔷

1️⃣ Build the graph as an adjacency list of pairs {node, weight}.

2️⃣ Use a `distance[]` array of type `long long` initialized to 1e18.
    - This prevents integer overflow for large edge weights.

3️⃣ Maintain a `ways[]` array to count the number of shortest paths to each node.
    - Initialize ways[src] = 1.

4️⃣ Use a min-heap (priority queue) storing {distance, node}.

5️⃣ While the priority queue is not empty:
    - Pop the node with the smallest current distance.
    - For all its adjacent nodes:
        a) If a shorter distance is found, update `distance[]` and reset `ways[]` to current node's ways.
        b) If the same shortest distance is found again, add the current node's ways to `ways[adj_node]`.

6️⃣ Return the number of ways to reach the destination node modulo 1e9+7.

✅ Time Complexity: O(E * log V), efficient for sparse graphs.
*/

// CODE ->>>>

    int countPaths(int n, vector<vector<int>>& arr) {

        vector<pair<int,int>>adj[n];
        for (auto ele : arr){
            int u = ele[0];
            int v = ele[1];
            int w = ele[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<long long>dis(n,1e18); // use long long to avoid overflow
        vector<int>ways(n,0);
        dis[0] = 0;
        ways[0] = 1;

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq; 
        pq.push({0,0}); // pq -> {distance , source}

        while(!pq.empty()){
            auto ele  = pq.top();
            pq.pop();
            long long curr_dis = ele.first;
            int curr_node = ele.second;
            
            for(auto nbr : adj[curr_node]){
                int edg_wt = nbr.second;
                int adj_node = nbr.first;

        // this is the first time we have reach the adj_node with minm dis
        // so we just update distance and ways will be same as prev node as curr_node
                if(edg_wt + curr_dis < dis[adj_node]){
                    dis[adj_node] = edg_wt + curr_dis;
                    pq.push({edg_wt + curr_dis ,adj_node});
                    ways[adj_node] = ways[curr_node];
                }
// here we are not reaching thr first time and thats why we got another path with the same distance
// so we have just update number of ways not distance
                else if(edg_wt + curr_dis == dis[adj_node]){
                    ways[adj_node] = (ways[curr_node] + ways[adj_node]) % mod ;
                }
            }
        }
        return ways[n-1] % mod ;
    }

/* write core logic here */
void solve(){

    // INPUT :
    
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

