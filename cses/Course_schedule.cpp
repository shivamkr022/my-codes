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

bool dfs(int node, vector<vector<int>> &adj, vector<int> &state, stack<int> &s) {
    state[node] = 1; // visiting
    for (auto nbr : adj[node]) {
        if (state[nbr] == 0) {
            if (!dfs(nbr, adj, state, s)) return false;
        }
        else if (state[nbr] == 1) { // back edge -> cycle
            return false;
        }
    }
    state[node] = 2; // visited
    s.push(node);
    return true;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v); // Directed edge only
    }

    vector<int> state(n, 0); // 0 = unvisited, 1 = visiting, 2 = visited
    stack<int> s;

    for(int i = 0; i < n; i++){
        if(state[i] == 0){
            if(!dfs(i, adj, state, s)) {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }

    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top() + 1); // convert to 1-based
        s.pop();
    }

    for(int ele : ans){
        cout << ele << " ";
    }
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
