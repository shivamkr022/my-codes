#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout << "errr----  " << #x << " " << x << endl
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
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // Prefix sum array
    vector<int> pre(n);
    pre[0] = arr[0];
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + arr[i];
    }

    int sum = pre[n - 1]; 
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        l--; r--;  // 0-based indexing
        int diff = pre[r] - (l > 0 ? pre[l - 1] : 0);  
        int rem = sum - diff; 
        int final = rem + (r - l + 1) * k;
        if (final % 2 == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
