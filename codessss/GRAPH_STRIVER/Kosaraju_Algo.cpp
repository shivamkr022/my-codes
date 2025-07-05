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
  ------------------------------------------------------
 |                                                    |
 |        Kosaraju’s Algorithm — Step by Step 💡       |
 |                                                    |
  ------------------------------------------------------

 🧠 Purpose: To find the number of Strongly Connected Components (SCCs)
 📌 Use only on directed graphs!

 ✨ STEPS:

 1️⃣ Do a normal DFS and push nodes onto a stack in the order of finishing time.
     → This gives the order in which nodes finish (like topo sort).

 2️⃣ Reverse the graph (transpose edges).
     → For every edge u → v, make it v → u.

 3️⃣ Do DFS on the reversed graph using the stack order.
     → Each DFS from an unvisited node gives one full SCC.

 4️⃣ Count the number of DFS runs in the reversed graph = number of SCCs.

  🔁 Time Complexity: O(N + E)
*/
 

void dfs(int node , vector<vector<int>> &adj , vector<int> &vis , stack<int> &st){
    vis[node] = 1;
    for(auto nbr : adj[node]){
        if(!vis[nbr]){
            dfs(nbr,adj,vis,st);
        }
    }
    st.push(node);
}

void dfs1(int node , vector<vector<int>> &rev_adj , vector<int> &vis1){
    vis1[node] = 1;
    for(auto nbr : rev_adj[node]){
        if(!vis1[nbr]){
            dfs1(nbr,rev_adj,vis1);
        }
    }
}

int kosaraju(vector<vector<int>> &adj) {
    int n = adj.size(); // Total number of nodes

    // Step 1: First DFS to fill stack based on finishing times
    vector<int> vis(n, 0);
    stack<int> st;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i, adj, vis, st);
        }
    }

    // Step 2: Reverse the graph (transpose)
    vector<vector<int>> rev_adj(n);
    for(int u = 0; u < n; u++){
        for(int v : adj[u]) {
            rev_adj[v].push_back(u); // reverse direction
        }
    }

    // Step 3: DFS on reversed graph in stack (finishing time) order
    vector<int> vis1(n, 0);
    int count_scc = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis1[node]){
            count_scc++;
            dfs1(node, rev_adj, vis1); // explore one SCC
        }
    }
    // Step 4: Return total number of strongly connected components
    return count_scc;
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

