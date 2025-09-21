/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Shivam             |
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
using namespace std;

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
#define int long long
#define mod 1000000007

// ---------- Global variables ----------
int n;
vector<int> arr;          // array to store elements
struct node {
    int minm;
};
node tree[800000];         // 4*n is safe size

// ---------- Merge function ----------
node merge(node a, node b){
    node ans;
    ans.minm = min(a.minm, b.minm);
    return ans;
}

// ---------- Build segment tree ----------
void build(int idx, int l, int r) {
    if(l == r){
        tree[idx].minm = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2*idx, l, mid);
    build(2*idx+1, mid+1, r);
    tree[idx] = merge(tree[2*idx], tree[2*idx+1]);
}

// ---------- Query ----------
node query(int idx, int l, int r, int lq, int rq){
    // No overlap
    if(r < lq || l > rq){
        node ans;
        ans.minm = LLONG_MAX; // neutral value for min
        return ans;
    }
    // Full overlap
    if(lq <= l && r <= rq){
        return tree[idx];
    }
    // Partial overlap
    int mid = (l + r) / 2;
    node left = query(2*idx, l, mid, lq, rq);
    node right = query(2*idx+1, mid+1, r, lq, rq);
    return merge(left, right);
}

// ---------- Solve function ----------
void solve(){
    int q;
    cin >> n >> q;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    build(1, 0, n-1); // build segment tree once

    while(q--){
        int a, b;
        cin >> a >> b;
        a--, b--; // convert to 0-based indexing
        node ans = query(1, 0, n-1, a, b);
        cout << ans.minm << endl;
    }
}

// ---------- Main ----------
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
