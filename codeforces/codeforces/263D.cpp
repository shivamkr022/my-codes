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

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int depth[MAXN], parent[MAXN];
int n, m, k;
bool found = false;

void dfs(int u, int p, int d) {
    depth[u] = d;
    parent[u] = p;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (!depth[v]) {
            dfs(v, u, d + 1);
            if (found) return;
        }
        else if (depth[u] - depth[v] + 1 >= k + 1) {
            vector<int> cycle;         // Cycle detected
            int curr = u;
            while (curr != v) {
                cycle.push_back(curr);
                curr = parent[curr];
            }
            cycle.push_back(v);
            cout << cycle.size() << endl;
            for (int node : cycle)
                cout << node << ' ';
            cout <<endl;
            found = true;
            return;
        }
    }
}

/* write core logic here */
void solve(){
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);   // create adj list
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!depth[i]) {
            dfs(i, -1, 1);
            if (found) break;
        }
    }
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

