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
🔷 WHEN TO USE DIJKSTRA’S ALGORITHM 🔷

✅ Use Dijkstra when:
1️⃣ You are asked to find the **shortest path** from a **single source** to all nodes (or to one destination).
2️⃣ All edge weights are **non-negative** (i.e., ≥ 0).
3️⃣ The graph is either **undirected** or **directed**.
4️⃣ You want an efficient solution for **sparse graphs** using priority queue + adjacency list.

❌ Don't use Dijkstra if:
- The graph has **negative weight edges** ➝ use **Bellman-Ford** instead.
- You need to find **all-pairs shortest paths** ➝ use **Floyd-Warshall**.
- The graph is **unweighted** ➝ use **BFS** for shortest path.

---

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

---

⏱️ Time Complexity:
    - O((E + V) * logV), where:
        - V is the number of vertices,
        - E is the number of edges,
        - logV from priority queue operations.

✅ Most efficient for sparse graphs using: Min-Heap + Adjacency List.
*/


         // CODE LOGIC

vector<int> dijkstra(int n, vector<vector<int>> &edges, int src) {
        
     vector<pair<int, int>> adj[n];
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int>dis(n,INT_MAX);
        dis[src] = 0;
        pq.push({0,src}); // it stores {dis ,Node} -> dis till node src -> src will chnage acc to node
        while(!pq.empty()){
            int curr_dis = pq.top().first;
            int curr_node = pq.top().second;
            // now we traverse on curr_ node so pop it from pq
            pq.pop();
            
            for(auto nbr : adj[curr_node]){
                int edg_wt = nbr.second;
                int adj_node = nbr.first;
                if(curr_dis + edg_wt < dis[adj_node]){
                    dis[adj_node] = edg_wt + curr_dis;
                    pq.push({dis[adj_node],adj_node});
                }
            }
        }
        return dis ;
   }
void solve(){

    // --->>>> INPUT
    
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

