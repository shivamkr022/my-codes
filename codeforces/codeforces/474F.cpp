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

#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cout << "errr---- " << #x << " " << x << endl
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
int n, t;
vector<int> arr;
struct node {
    int g, cnt; // gcd and count of elements equal to gcd
};
node tree[800000]; // safe size 4*n

// ---------- Merge / Combine ----------
node merge(node a, node b) {
    if(a.g == -1) return b;
    if(b.g == -1) return a;
    node res;
    res.g = __gcd(a.g, b.g);
    res.cnt = 0;
    if(a.g == res.g) res.cnt += a.cnt;
    if(b.g == res.g) res.cnt += b.cnt;
    return res;
}

// ---------- Build Segment Tree ----------
void build(int idx, int l, int r) {
    if(l == r) {
        tree[idx].g = arr[l];
        tree[idx].cnt = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(2*idx, l, mid);
    build(2*idx+1, mid+1, r);
    tree[idx] = merge(tree[2*idx], tree[2*idx+1]);
}

// ---------- Query ----------
node query(int idx, int l, int r, int ql, int qr) {
    if(qr < l || ql > r) return {-1, 0};
    if(ql <= l && r <= qr) return tree[idx];
    int mid = (l + r) / 2;
    node left = query(2*idx, l, mid, ql, qr);
    node right = query(2*idx+1, mid+1, r, ql, qr);
    return merge(left, right);
}

// ---------- Solve ----------
void solve() {
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    build(1, 0, n-1);

    cin >> t;
    while(t--) {
        int l, r;
        cin >> l >> r;
        l--, r--; // convert to 0-based indexing
        node res = query(1, 0, n-1, l, r);
        int total = r - l + 1;
        cout << total - res.cnt << endl;
    }
}

// ---------- Main ----------
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif

    int tt = 1;
    //cin >> tt;
    while(tt--) solve();
    return 0;
}
