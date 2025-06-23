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
🔷 STEPS FOR DIJKSTRA’S ALGORITHM 🔷

1️⃣ Build the graph:
    - Represent the graph using an adjacency list.
    - Each node stores pairs: {adjacent_node, weight}.

2️⃣ Initialize distance array:
    - Create a distance array `dis[]` of size `n` and initialize all values as `INF`.
    - Set the source node distance as 0: `dis[src] = 0`.

3️⃣ Create a min-heap priority queue:
    - It stores pairs: {distance_so_far, current_node}.
    - Initialize it with the source node: pq.push({0, src}).

4️⃣ Start the Dijkstra loop:
    - While the priority queue is not empty:
        a) Extract the top (minimum distance) element.
        b) For all adjacent nodes:
            i)   Calculate new distance = current_distance + edge_weight.
            ii)  If new distance < dis[adj_node], update it.
            iii) Push the updated {new_distance, adj_node} into the PQ.

5️⃣ Once the loop ends:
    - The `dis[]` array now holds the shortest distances from `src` to all other nodes.

6️⃣ Return the `dis[]` array as the result.

⏱️ Time Complexity:
    - O((E + V) * logV), where:
        - V is the number of vertices,
        - E is the number of edges,
        - logV from priority queue operations.

✅ Most efficient for sparse graphs using: Min-Heap + Adjacency List.
*/


   // // // DIJKSTRA ALGORITHM

 vector<int> dijkstra(int n, vector<vector<int>> &edges, int src) {
        
     vector<pair<int, int>> adj[n];
        for (auto &edge : edges) {
            int u = edge[0];          // adj list weighted
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // min heap
        
        vector<int>dis(n,INT_MAX); // init all dis node with infinity
        dis[src] = 0;
        pq.push({0,src}); // it stores {dis ,Node} -> dis till node src -> src will chnage acc to node
        
        while(!pq.empty()){
            int curr_dis = pq.top().first;  // curr dis from src to that node
            int node  =  pq.top().second;   // that node 
            pq.pop();  // it wil travesre all its nbr so delete this
            
            for (auto nbr : adj[node]){  // traversal start
                int edg_wt = nbr.second;   // curr edge wt
                int adj_node = nbr.first;  // node where we are going 
                
                if(curr_dis + edg_wt < dis[adj_node]){ // new short path
                    dis[adj_node]  = curr_dis + edg_wt ; // update dis
                    pq.push({dis[adj_node],adj_node});  // push to pq
                }
            }
        }
        return dis ;
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

