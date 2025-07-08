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

vector<pair<int, int>> ans;
set<pair<int, int>> used;
int timer = 0;
int bridge = 0;

int tarjan(int node, int par, vector<vector<int>> &adj, vector<int>& vis, vector<int>& ins_time, vector<int>& lowest_ins_time) {
    vis[node] = 1;
    ins_time[node] = lowest_ins_time[node] = timer++;
    
    for (auto nbr : adj[node]) {
        if (nbr == par) continue;
        
        if (!vis[nbr]) {
            tarjan(nbr, node, adj, vis, ins_time, lowest_ins_time);
            lowest_ins_time[node] = min(lowest_ins_time[node], lowest_ins_time[nbr]);

            if (lowest_ins_time[nbr] > ins_time[node]) {
                bridge++;
            }
        }
        else{
            lowest_ins_time[node] = min(lowest_ins_time[node], ins_time[nbr]);
        }
    }

    return bridge;
}

void assign_dir(int node, vector<vector<int>> &adj, vector<int> &vis1) {
    vis1[node] = 1;
    for (auto nbr : adj[node]) {
        int a = min(node, nbr);
        int b = max(node, nbr);

        if (used.count({a, b})) continue;

        used.insert({a, b});
        ans.push_back({node, nbr});

        if (!vis1[nbr]) {
            assign_dir(nbr, adj, vis1);
        }
    }
}

/* write core logic here */
void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Reset globals (important for multiple testcases)
    timer = 0;
    bridge = 0;
    ans.clear();
    used.clear();

    vector<int> vis(n, 0), ins_time(n, 0), lowest_ins_time(n, 0);
    tarjan(0, -1, adj, vis, ins_time, lowest_ins_time);

    if (bridge > 0) {
        cout << 0 << endl;
        return;
    }

    vector<int> vis1(n, 0);
    assign_dir(0, adj, vis1);

    for (auto ele : ans) {
        cout << ele.first + 1 << " " << ele.second + 1 << endl;
    }
}
/* logic ends */

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    int t;
    //cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
