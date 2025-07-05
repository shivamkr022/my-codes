/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Shivam            |
 |                                        |
  ------------------------------------------
    \        ,     ,        /
      \      |     |      /
         \   \_/   /
           \  -----  /
             \_/
  
  Happy coding!

──────────────────────────────────────────────
📝 Revision Notes – Check if Graph is Strongly Connected (Kosaraju)
──────────────────────────────────────────────

Goal:
- Given a directed graph with `n` nodes and `m` edges, check if it's **strongly connected**.
- If **YES**, print "YES"
- If **NO**, print "NO" and print a pair of nodes `a`, `b` such that `a` cannot reach `b`

Steps:
1. ✅ Build the graph (`adj`) and its reverse (`rev_adj`).
2. ✅ Run DFS on original graph to get **finishing order** → store in a stack.
3. ✅ Run DFS on reversed graph (in order from stack) to identify **SCCs**.
   - Count the number of SCCs.
   - Store the **leader node** of each SCC.
4. ✅ If only one SCC exists → print `"YES"`.
5. ✅ Else:
   - Pick any two different SCC leaders (say `a = leaders[0]`, `b = leaders[1]`)
   - Check if `a → b` is reachable using DFS on original graph.
     - If not → print `"NO"` and `a b`
   - Otherwise check if `b → a` is reachable
     - If not → print `"NO"` and `b a`
   - If both reachable → (rare edge case), but would continue checking (not needed here due to SCC > 1 check)

Time Complexity:
- O(N + M) for both DFS passes (Kosaraju)

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

void dfs_check(int node, vector<vector<int>> &adj, vector<int> &vis) {
    vis[node] = 1;
    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            dfs_check(nbr, adj, vis);
        }
    }
}

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

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<vector<int>>rev_adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }
    vector<int> vis(n+1,0) ;
    stack<int> st ;

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,adj,vis,st);
        }
    }

    vector<int> vis1(n+1, 0);
    int count_scc = 0;
    vector<int>leaders;

    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis1[node]){
            leaders.push_back(node) ;
            count_scc++;
            dfs1(node, rev_adj, vis1); // explore one SCC
        }
    }

    if(count_scc <=1){
        cout<<"YES"<<endl;
        return ;
    }

    int a = leaders[0];
    int b = leaders[1];

    vector<int> vis_reach(n + 1, 0);
    dfs_check(a, adj, vis_reach);
    if(!vis_reach[b]) {
        cout << "NO" << endl;
        cout << a << " " << b << endl;
        return;
    }

    fill(vis_reach.begin(), vis_reach.end(), 0);
    dfs_check(b, adj, vis_reach);
    if(!vis_reach[a]) {
        cout << "NO" << endl;
        cout << b << " " << a << endl;
        return;
    }
}

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
