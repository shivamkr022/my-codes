/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Shivam            |
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
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

const int N = 2e5 + 5;
int f[N], g[N];

/* write core logic here */
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> f[i];
        --f[i];
    }
    for (int i = 0; i < n; i++) {
        if (f[i] != -1) g[f[i]] = 1;
    }
    vector<int> x, y, z;
    for (int i = 0; i < n; i++) {
        if (f[i] == -1 && g[i] == 0) z.push_back(i);
        else if (f[i] == -1) x.push_back(i);
        else if (g[i] == 0) y.push_back(i);
    }
    if (z.size() > 1) {
        for (int i = 0; i < z.size(); i++) {
            f[z[i]] = z[(i + 1) % z.size()];
        }
        for (int i = 0; i < x.size(); i++) {
            f[x[i]] = y[i];
        }
    }
    else {
        if (!z.empty()) {
            x.push_back(z[0]);
            y.push_back(z[0]);
        }
        reverse(y.begin(), y.end());
        for (int i = 0; i < x.size(); ++i) {
            f[x[i]] = y[i];
        }
    }
    for (int i = 0; i < n; i++){
     cout << f[i] + 1 << " ";
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
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}