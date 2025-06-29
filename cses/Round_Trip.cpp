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

bool dfs(int node, int parentNode, vector<vector<int>>& adj, vector<int>& vis, vector<int>& parent, int& cycleStart, int& cycleEnd) {
    vis[node] = 1;
    parent[node] = parentNode;

    for (int neighbor : adj[node]) {
        if (!vis[neighbor]) {
            if (dfs(neighbor, node, adj, vis, parent, cycleStart, cycleEnd))
                return true;
        } 
        else if (neighbor != parentNode) {  // cycle found
            cycleStart = neighbor;
            cycleEnd = node;
            return true;
        }
    }
    return false;
}

/* write core logic here */
void solve(){
int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--; // Convert to 0-based index
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n, 0), parent(n, -1);
    int cycleStart = -1, cycleEnd = -1;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (dfs(i, -1, adj, vis, parent, cycleStart, cycleEnd)) {
                break;
            }
        }
    }

    if (cycleStart == -1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    vector<int> cycle;
    cycle.push_back(cycleStart);
    for (int v = cycleEnd; v != cycleStart; v = parent[v]) {
        cycle.push_back(v);
    }

    cycle.push_back(cycleStart);
    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << endl;
    for (int node : cycle)
        cout << node + 1 << " "; 
    cout << endl;
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

