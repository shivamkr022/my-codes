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
  ✅ Graph Type for Prim's Algorithm:
     - Undirected
     - Weighted
     - Connected
       (or run Prim’s separately for each connected component if disconnected)

  ✅ What Problem Does Prim’s Solve?
     - Finds Minimum Spanning Tree (MST):
         → Connects all nodes with **minimum total edge weight**
         → No cycles
         → Exactly (n−1) edges for n nodes
*/

/*
    ✅✅ WHEN TO USE THIS SPANNING TREE CODE ✅✅

    -> Use only when graph is undirected
    -> Graph must be connected (i.e., all nodes must be reachable)
    -> You are asked to find:
        1) Minimum Spanning Tree (MST)
        2) Minimum cost to connect all nodes
    -> Input will be: n nodes and m weighted edges

    ✅✅ WHERE TO USE THIS CODE ✅✅

    -> Inside solve():
        - Take input: n, m
        - Construct adjacency list like:
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});  // undirected edge
        - Then simply call:
            spanningTree(n, adj);
*/

int spanningTree(int n, vector<vector<int>> adj[]) {

    // Step 1: Min Heap to always pick edge with min weight
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq ;

    vector<int>vis(n,0);  // visited nodes tracker

    pq.push({0,0});  // {weight, starting node}
    int sum =0;      // stores total weight of MST

    // Step 2: Prim's Algo - loop until all nodes are included
    while(!pq.empty()){
        auto ele = pq.top();
        pq.pop();
        int curr_wt = ele.first;
        int curr_node = ele.second;

        if(vis[curr_node] == 1) continue; // skip already visited

        vis[curr_node] = 1; // mark current node visited
        sum += curr_wt ;    // include current edge in MST

        // Step 3: Push all unvisited neighbors to pq
        for(auto nbr : adj[curr_node]){
            int adj_node = nbr[0];
            int edg_wt = nbr[1] ;
            if(!vis[adj_node]){
                pq.push({edg_wt , adj_node}) ;
            }
        }
    }
    
    // Step 4: Final check if all nodes included in MST
    for(int i = 0; i < n; i++){
        if(vis[i] == 0){
            cout << "Graph is disconnected, MST doesn't exist!" << endl;
            return -1;
        }
    }

    return sum ;  // returns total weight of MST
}


/* write core logic here */
void solve(){

    /*
        Sample input section:

        int n, m;
        cin >> n >> m;

        vector<vector<int>> adj[n];

        for(int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});  // undirected
        }

        cout << spanningTree(n, adj) << endl;
    */
    
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
