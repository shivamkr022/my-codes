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
#define int long long
using namespace std;

int timer = 0;
int scc_cmp = 0;

void Tarjan(int node, vector<vector<int>> &adj, vector<int> &ins_time,
            vector<int> &lowest_ins_time, vector<int> &vis,
            vector<int> &onStack, stack<int> &st, vector<int> &store) {

    vis[node] = 1;
    ins_time[node] = lowest_ins_time[node] = timer++;
    st.push(node);
    onStack[node] = 1;

    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            Tarjan(nbr, adj, ins_time, lowest_ins_time, vis, onStack, st, store);
            lowest_ins_time[node] = min(lowest_ins_time[node], lowest_ins_time[nbr]);
        }
        else if (onStack[nbr]) {
            lowest_ins_time[node] = min(lowest_ins_time[node], ins_time[nbr]);
        }
    }

    if (lowest_ins_time[node] == ins_time[node]) {
        while (true) {
            int u = st.top(); 
            st.pop();
            onStack[u] = 0;
            store[u] = scc_cmp;
            if (u == node) break;
        }
        scc_cmp++;
    }
}

void solve(){
    int n, m, s;
    cin >> n >> m >> s;
    s--; // 0-indexed

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }

    vector<int> ins_time(n, 0);
    vector<int> lowest_ins_time(n, 0);
    vector<int> vis(n, 0);
    vector<int> store(n, 0);
    vector<int> onStack(n, 0);
    stack<int> st;

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            Tarjan(i, adj, ins_time, lowest_ins_time, vis, onStack, st, store);
        }
    }

    // Build condensed graph of SCCs
    vector<set<int>> scc_adj(scc_cmp);
    vector<int> indegree(scc_cmp, 0);

    for(int u = 0; u < n; u++) {
        for(int v : adj[u]) {
            if(store[u] != store[v]) {
                if(scc_adj[store[u]].insert(store[v]).second) {
                    indegree[store[v]]++;
                }
            }
        }
    }

    int src_scc = store[s];
    int cnt = 0;
    for(int i = 0; i < scc_cmp; i++) {
        if(indegree[i] == 0 && i != src_scc) {
            cnt++;
        }
    }

    cout << cnt << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
