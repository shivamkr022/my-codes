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

class DisjointSet{
    vector<int>size;
    vector<int>parent;

public:

    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1; // size were 1 initially for all nodes or components
        }
    }

    int find_par(int node){
        if(node == parent[node]){
            return node ;  // we got ultimate parent
        }
        return parent[node] = find_par(parent[node]) ; // By recursion we get ultimate parent of Node
    }

    void UnionBySize(int u , int v){
        int ult_par_u = find_par(u);
        int ult_par_v = find_par(v);

        if(ult_par_u == ult_par_v) return ;

        if(size[ult_par_u] > size[ult_par_v]){
            parent[ult_par_v] = ult_par_u;
            size[ult_par_u] += size[ult_par_v] ;
        }
        else{  
             // size[ult_par_u] < = size[ult_par_v]
            parent[ult_par_u] = ult_par_v;
            size[ult_par_v] += size[ult_par_u];
        }
    }

};

/* write core logic here */
void solve(){

    DisjointSet ds(7);
    ds.UnionBySize(1,2);
    ds.UnionBySize(2,3);
    ds.UnionBySize(4,5);
    ds.UnionBySize(6,7);
    ds.UnionBySize(5,7);

    if(ds.find_par(3) == ds.find_par(7)){
        cout<<" same" <<endl;
    }
    else{
        cout<<"not same " << endl;
    }

    ds.UnionBySize(3,7);

        if(ds.find_par(3) == ds.find_par(7)){
        cout<<" same "<<endl;
    }
    else{
        cout<<" not same " << endl;
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

