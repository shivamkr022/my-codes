/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Shivam           |
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

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout << "errr----  " << #x << " " << x << endl
#define print(v)                          \
    do {                                  \
        cout << "vect--" << #v << " = [ ";\
        for (int i = 0; i < v.size(); i++) { \
            cout << v[i] << " ";          \
        }                                 \
        cout << " ]" << endl;             \
    } while (0)
#else
#define debug(x)
#define print(v)
#endif
#define endl "\n"
#define int long long
#define mod 1000000007
#define mn(a, b, c) min(a, min(b, c))
#define mx(a, b, c) max(a, max(b, c))
using namespace std;

/* write core logic here */
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n + 2);
    for (int i = 0; i < n + 2; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int xx = arr[n + 1]; 
    int yy = arr[n];    

    if (sum == yy) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    sum += yy; 
    bool found = false;
    int remove_idx = -1;

    for (int i = 0; i <= n; i++) {
        if (sum - arr[i] == xx) {
            found = true;
            remove_idx = i;
            break;
        }
    }

    if (!found) {
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i <= n; i++) {
        if (i != remove_idx) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}
/* logic ends */

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
