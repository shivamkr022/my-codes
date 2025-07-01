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

int spanningTree(int n, vector<vector<int>> adj[]) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> vis(n, 0);
    vector<pair<int, int>> mst_edges; // store (from, to) edges
    vector<int> parent(n, -1); // to track which node added the current node

    pq.push({0, 0});  // {weight, node}
    int sum = 0;

    while (!pq.empty()) {
        auto ele = pq.top();
        pq.pop();
        int curr_wt = ele.first;
        int curr_node = ele.second;

        if (vis[curr_node]) continue;
        vis[curr_node] = 1;
        sum += curr_wt;

        // if parent exists, store the edge
        if (parent[curr_node] != -1) {
            mst_edges.push_back({parent[curr_node], curr_node});
        }

        for (auto nbr : adj[curr_node]) {
            int adj_node = nbr[0];
            int edg_wt = nbr[1];
            if (!vis[adj_node]) {
                pq.push({edg_wt, adj_node});
                parent[adj_node] = curr_node;
            }
        }
    }

    // Print MST edges
    cout << "MST Edges:" << endl;
    for (auto edge : mst_edges) {
        cout << edge.first << " - " << edge.second << endl;
    }

    return sum;
}

/* write core logic here */
void solve(){

    // INPUT
    
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

