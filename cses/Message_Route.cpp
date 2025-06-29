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

void bfs(int node , vector<vector<int>> &adj ,vector<int> &vis ,vector<int> & par){
    vis[node] = 1;
    queue<int>q;
    q.push(node);
    par[node] = -1;

    while(!q.empty()){
        int curr_node = q.front();
        q.pop();
        for(auto nbr : adj[curr_node]){
            if(!vis[nbr]){
                vis[nbr] = 1;
                par[nbr] = curr_node ;
                q.push(nbr);
            }
        }
    }
}

/* write core logic here */
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>vis(n,0);
    vector<int>par(n,-1);

    bfs(0, adj, vis, par); // BFS from node 0 (1 in input)

    if(!vis[n - 1]) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    vector<int> path;
    int curr = n - 1;
    while(curr != -1) {
        path.push_back(curr);
        curr = par[curr];
    }

    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for (int ele : path) cout << (ele + 1) << " "; 
    cout << endl;

}
/* logic ends */

    /*
    ---------------------------------------------
    🧪 Dry Run on Input:
    5 5
    1 2
    1 3
    1 4
    2 3
    5 4

    After converting to 0-indexed:
    adj = {
        0: [1, 2, 3]
        1: [0, 2]
        2: [0, 1]
        3: [0, 4]
        4: [3]
    }

    BFS starts at node 0:
    vis = [1, 0, 0, 0, 0]
    par = [-1, ?, ?, ?, ?]
    q = [0]

    → pop 0 → neighbors: 1, 2, 3
      vis = [1, 1, 1, 1, 0]
      par = [-1, 0, 0, 0, ?]
      q = [1, 2, 3]

    → pop 1 → neighbors: 0, 2 → already visited
    → pop 2 → neighbors: 0, 1 → already visited
    → pop 3 → neighbors: 0, 4
      vis[4] = 1
      par[4] = 3
      q = [4]

    → pop 4 → neighbor 3 → already visited
    BFS done.

    vis = [1, 1, 1, 1, 1]
    par = [-1, 0, 0, 0, 3]

    Reconstruct path from node 4 (which is 5 in input):

    path = []
    curr = 4
    → path.push(4)
    → par[4] = 3 → path.push(3)
    → par[3] = 0 → path.push(0)
    → par[0] = -1 → stop

    path = [4, 3, 0] → reversed → [0, 3, 4]
    → +1 for 1-indexed: 1 4 5

    Output:
    3
    1 4 5
    ---------------------------------------------
    */

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

