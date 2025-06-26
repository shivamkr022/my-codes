// /*
//   ------------------------------------------
//  |                                        |
//  |      Code Crafted by Shivam            |
//  |                                        |
//   ------------------------------------------
//     \        ,     ,        /
//       \      |     |      /
//          \   \_/   /
//            \  -----  /
//              \_/

//   Happy coding! 
// */

// #include<bits/stdc++.h>
// #ifndef ONLINE_JUDGE
// #define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
// #define print(v) do { \
//                     cout << "vect--" << #v << " = [ "; \
//                     for (int i = 0; i < v.size(); i++) { \
//                         cout << v[i] << " "; \
//                     } \
//                     cout << " ]" << endl; \
//                 } while(0)
// #else
// #define debug(x)
// #define print(v)
// #endif

// #define endl "\n"
// #define int long long int
// #define mod 1000000007
// #define mn(a,b,c) min(a,min(b,c))
// #define mx(a,b,c) max(a,max(b,c))
// using namespace std;

// vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {

//     vector<vector<pair<int,int>>> adj(n + 1); 

//     for(auto& edge : edges){
//         int u = edge[0];
//         int v = edge[1];
//         int w = edge[2];
//         adj[u].push_back({v,w});
//         adj[v].push_back({u,w});
//     }

//     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
//     vector<int> dis(n + 1, 1e18);
//     vector<int> par(n + 1);

//     for(int i = 1; i <= n; i++) par[i] = i;

//     dis[1] = 0;
//     pq.push({0, 1});

//     while(!pq.empty()) {
//         auto it = pq.top(); // it is of type pair<int, int>
//         pq.pop();
//         int curr_dis = it.first;
//         int curr_node = it.second;

//         if (curr_dis > dis[curr_node]) continue;

//         for(auto& nbr : adj[curr_node]){
//             int adj_node = nbr.first;
//             int edge_wt = nbr.second;

//             if(curr_dis + edge_wt < dis[adj_node]){
//                 dis[adj_node] = curr_dis + edge_wt;
//                 pq.push({dis[adj_node], adj_node});
//                 par[adj_node] = curr_node;
//             }
//         }
//     }

//     if(dis[n] == 1e18) return {-1};  // no path

//     vector<int> path;
//     int node = n;
//     while (node != par[node]) {
//         path.push_back(node);
//         node = par[node];
//     }
//     path.push_back(node);
//     reverse(path.begin(), path.end());
//     return path;
// }

// /* write core logic here */
// void solve(){
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> edges;

//     for (int i = 0; i < m; i++) {
//         int u, v, w;
//         cin >> u >> v >> w;            // INPUT
//         edges.push_back({u, v, w});
//     }

//     vector<int> path = shortestPath(n, m, edges);
//     if (path.size() == 1 && path[0] == -1) {
//         cout << -1 << endl;
//     }
//     else {
//         for (int node : path) cout << node << " ";
//         cout << endl;
//     }
// }
// /* logic ends */

// signed main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     #ifndef ONLINE_JUDGE
//         freopen("Error.txt" , "w" , stderr);
//     #endif
//     int t;
//     t = 1;
//     while(t--){
//         solve();
//     }
//     return 0;
// }
