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

/*
  🔍 What this code does:
  -------------------------
  ✅ Implements Kruskal's Algorithm to find the Minimum Spanning Tree (MST)
  ✅ Uses Disjoint Set (Union-Find) with:
     - Path Compression for fast find()
     - Union by Size for efficient union()
  ✅ Time complexity: O(M log M) where M = number of edges

  🧠 Why this order of functions in Disjoint Set?
  ------------------------------------------------
  1. Constructor:
     - Initializes each node's parent as itself and size as 1
  2. find_par():
     - Finds the ultimate parent of a node with path compression
  3. UnionBySize():
     - Merges two components based on their size

  🛠 Steps of Kruskal's MST:
  ----------------------------
  1. Sort all edges by weight
  2. For each edge:
     - If nodes belong to different components (i.e., no cycle)
     - Add the edge to MST and merge the components using DSU

  🐶 Fun analogy (woof woof!):
  ---------------------------------
  Think of each node as a dog in a pack 🐕
  - Every dog starts as its own pack leader
  - When 2 packs unite, the bigger pack absorbs the smaller
  - The leader is updated (find_par) so every dog knows the alpha 🐾

  🧩 Perfect for problems involving:
  - MST (Minimum Spanning Tree)
  - Connected components
  - Cycle detection in undirected graphs

  🛡 No adj list needed here — Kruskal works edge-based, not node-based!
*/

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

class DisjointSet {
    vector<int> size;     // stores size of component
    vector<int> parent;   // stores parent of node

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;   // initially parent is self
            size[i] = 1;     // size of each component is 1
        }
    }
    // Path compression: flattens the tree
    int find_par(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = find_par(parent[node]); // path compressed
    }
    // Union by size: attach smaller tree under larger one
    void UnionBySize(int u, int v) {
        int ult_par_u = find_par(u);
        int ult_par_v = find_par(v);

        if (ult_par_u == ult_par_v) return; // already in same component

        // Attach smaller size tree under larger one
        if (size[ult_par_u] > size[ult_par_v]) {
            parent[ult_par_v] = ult_par_u;
            size[ult_par_u] += size[ult_par_v];
        }
        else {
            parent[ult_par_u] = ult_par_v;
            size[ult_par_v] += size[ult_par_u];
        }
    }
};


class Solution {
  public:
    int kruskalsMST(int n, vector<vector<int>> &edges) {
        
    sort(edges.begin(), edges.end(), [&](vector<int>& p, vector<int>& q) {
    return p[2] < q[2]; // sort by weight
    });
    
    DisjointSet ds(n);
    int mst_wt = 0;
    for(auto ele : edges){
        int a = ele[0];
        int b = ele[1];
        int wt = ele[2];
        
        if(ds.find_par(a) != ds.find_par(b)){
            mst_wt += wt;
            ds.UnionBySize(a,b);
        }
     }
     return mst_wt ;
   }
};
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

