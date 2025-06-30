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

/*
-----------------------------------------------------
🧠 TOPOLOGICAL SORT USING KAHN’S ALGORITHM (BFS)

Steps:
1️⃣ Build the directed graph using adjacency list.
2️⃣ Maintain an indegree array to count incoming edges for each node.
3️⃣ Push all nodes with indegree 0 into the queue (they can be taken first).
4️⃣ While queue is not empty:
   - Pop node, add to topological order.
   - Decrease indegree of its neighbors.
   - If any neighbor's indegree becomes 0, push it into queue.
5️⃣ If topological order contains all nodes, return true.
   - Else, a cycle exists → topological sort not possible.

⛔ This algorithm also **detects cycles** implicitly.

Time Complexity: O(V + E)
-----------------------------------------------------
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
   
/// KAHN'S ALGO OR BFS TOPO SORT
bool topoSort(int n, vector<vector<int>>& edges) {
    vector<vector<int>>adj(n);       // Step 1: Adjacency list
    vector<int>indegree(n,0);        // Step 2: Track incoming edges

    for(auto ele : edges){
        int u = ele[0];
        int v = ele[1];              // u -> v (directed)
        adj[u].push_back(v);
        indegree[v]++;              // Count incoming edge for v
    }

    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){         // Step 3: Nodes with indegree 0 can be processed first
            q.push(i);
        }
    }

    vector<int>topo;
    while(!q.empty()){              // Step 4: BFS traversal
        int node = q.front();
        q.pop();
        topo.push_back(node);       // Add to topological order

        for(auto nbr : adj[node]){  // Reduce indegree of neighbors
            indegree[nbr]--;
            if(indegree[nbr]==0){   // If indegree becomes 0, add to queue
                q.push(nbr);
            }
        }
    }

    // Step 5: Check if topo order includes all nodes (cycle detection)
    if(topo.size()==n){
        return true;
    }
    else{
        return false;
    }
}

/* write core logic here */
void solve(){
    /// INPUT
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
