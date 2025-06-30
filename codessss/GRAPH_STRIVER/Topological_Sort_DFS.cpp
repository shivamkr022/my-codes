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
🧠 TOPOLOGICAL SORT USING DFS (ONLY FOR DAG)

Steps:
1️⃣ Build the directed adjacency list from edges.
2️⃣ For each unvisited node, run DFS.
3️⃣ In DFS: after visiting all neighbors, push the current node to a stack.
4️⃣ At the end, popping from stack gives valid topological order.
⚠️ Works only if graph is a DAG. (Does NOT detect cycles by itself.)

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

/// TOPOLOGICAL SORT (DFS-based)
void dfs(int node , vector<vector<int>>&adj , vector<int>&vis , stack<int>&st ){
    vis[node]=1;  // Mark the current node visited

    // Go to all unvisited neighbors
    for(auto nbr : adj[node]){
        if(!vis[nbr]){
            dfs(nbr,adj,vis,st);  // Recursive DFS call
        }
    }

    // After visiting all children, push current node
    st.push(node);   // Node is ready to be ordered
}

/// Main function to return topological order
vector<int> topoSort(int n, vector<vector<int>>& edges) {
    vector<vector<int>>adj(n);

    // Step 1: Build adjacency list from edges
    for(auto ele : edges){
        int u = ele[0];
        int v = ele[1];      // edge from u -> v
        adj[u].push_back(v);
    }

    vector<int>vis(n,0);
    stack<int>st;

    // Step 2: DFS from every unvisited node
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,adj,vis,st);
        }
    }

    // Step 3: Pop from stack to get topological order
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans ;
}

/* write core logic here */
void solve(){

    // --->> INPUT

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
