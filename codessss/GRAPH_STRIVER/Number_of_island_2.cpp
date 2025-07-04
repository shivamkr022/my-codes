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

class DisjointSet {
    vector<int> size;     // stores size of component
    vector<int> parent;   // stores parent of node

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;   // initially parent is self
            size[i] = 1;     // size of each component is 1
        }
    }

    // Path compression: flattens the tree
    int find_par(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = find_par(parent[node]); // path compressed
    }

    // Union by size: attach smaller tree under larger one
    void UnionBySize(int u, int v) {
        int ult_par_u = find_par(u);
        int ult_par_v = find_par(v);

        if (ult_par_u == ult_par_v) return; // already in same component

        // Attach smaller size tree under larger one
        if (size[ult_par_u] > size[ult_par_v]) {
            parent[ult_par_v] = ult_par_u;
            size[ult_par_u] += size[ult_par_v];
        }
        else {
            parent[ult_par_u] = ult_par_v;
            size[ult_par_v] += size[ult_par_u];
        }
    }
};

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &arr){

	vector<vector<int>>vis(n,vector<int>(m,0));
    DisjointSet ds(n*m);
    int count = 0;
    vector<int>ans;
    for(auto ele : arr){
        int row = ele[0];
        int col = ele[1];
        if(vis[row][col] == 1){ // if already visted means already an island and island remains same
            ans.push_back(count);
            continue;
        }
        // not visited
        vis[row][col] = 1;
        count++;

        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};

        for(int i=0;i<4;i++){
            int new_row = row + dr[i];
            int new_col = col + dc[i];

            if(new_row < n and new_row >=0 and new_col < m and new_col >=0){ // valid cond for travel
                if(vis[new_row][new_col]==1){  // his neighbour is also visited
                    int node_no = row * m + col ;  // node no
                    int adj_node_no = new_row * m + new_col ; // adj node no

                    if(ds.find_par(node_no) != ds.find_par(adj_node_no)){ // node_no and adj_node no is neighbour
                        count--;   //  so it became a single island and count will be decreased 
                        ds.UnionBySize(node_no,adj_node_no); // connect the node now
                    }
                }
            }
        }
        ans.push_back(count);
    }
    return ans ;
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

