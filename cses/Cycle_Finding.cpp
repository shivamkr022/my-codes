// /*
//   ------------------------------------------
//  |                                        |
//  |      Code Crafted by Shivam     |
//  |                                        |
//   ------------------------------------------
//     \        ,     ,        /
//       \      |     |      /
//          \   \_/   /
//            \  -----  /
//              \_/
  
//   Happy coding! 
// */

// /* includes and all */

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
// void dfs(int node,vector<vector<pair<int, int>>> & adj,vector<int>pathvis,vector<int>vis){{
//     vis[node]=1;
//     pathvis[node]=1;
//     for(auto nbr : adj[node]){
//         if(!vis[nbr]){

//         }
//     }
// }
// }

// /* write core logic here */
// void solve(){
//     int n,m;
//     cin>>n>>m;
//     vector<vector<pair<int, int>>> adj(n);
//     for (int i = 0; i < m; ++i) {
//         int u, v, w;
//         cin >> u >> v >> w;  // directed edge from u to v with weight w
//         adj[u].push_back({v, w});
//     }
//     vector<int>vis(n,0);
//     vector<int>pathvis(n,0);
// }
// /* logic ends */

// signed main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     #ifndef ONLINE_JUDGE
//         freopen("Error.txt" , "w" , stderr);
//     #endif
//     int t;
//     //cin>>t;
//     t = 1;
//     while(t--){
//         solve();
//     }
// return 0;
// }

