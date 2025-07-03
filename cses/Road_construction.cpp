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
     int getSize(int node) {
         return size[find_par(node)];
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

/* write core logic here */
void solve(){
    int n,m;
    cin>>n>>m;
    int cmp = n; // initially;
    int grp = 1; // initially
    DisjointSet ds(n);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

    if (ds.find_par(u) != ds.find_par(v)) {
        ds.UnionBySize(u, v);
        cmp--; // one less component
    }
    grp = max(grp, ds.getSize(u)); // update largest component size
    cout << cmp << " " << grp << endl;
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

