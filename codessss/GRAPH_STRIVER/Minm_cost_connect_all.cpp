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

int minCostConnectPoints(vector<vector<int>>& points) {

    int n = points.size();
    vector<vector<pair<int,int>>> adj(n); //  {weight, neighbor}

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            adj[i].push_back({w, j});
            adj[j].push_back({w, i});
        }
    }
    // Prim’s MST starts here
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> vis(n, 0);

    pq.push({0, 0});  // {weight, start at node 0}
    int sum = 0;
    int visitedCount = 0;

    while (!pq.empty() && visitedCount < n) {

        auto ele = pq.top() ;
        pq.pop();
        int curr_wt = ele.first ;
        int curr_node = ele.second ;
        if (vis[curr_node]) continue;

        vis[curr_node] = 1;
        sum += curr_wt;
        visitedCount++;

        for (auto &nbr : adj[curr_node]) {
            int w = nbr.first, v = nbr.second;
            if (!vis[v]) {
                pq.push({w, v});
            }
        }
    }
    return sum;
}
/* write core logic here */
void solve(){
    
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

