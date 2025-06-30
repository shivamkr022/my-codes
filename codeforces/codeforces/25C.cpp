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

/* includes and all */

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
#define mn(a,b,c) min(a, min(b, c))
#define mx(a,b,c) max(a, max(b, c))

using namespace std;

/* write core logic here */
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> dist(n, vector<int>(n));
    // Read initial shortest path matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }
    int k;
    cin >> k;
    while (k--) {
        int u, v, wt;
        cin >> u >> v >> wt;
        --u; --v;
        // Try to update paths through the new road
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                int direct1 = dist[i][u] + wt + dist[v][j];
                int direct2 = dist[i][v] + wt + dist[u][j];

                int new_dist = min(dist[i][j], min(direct1, direct2));
                dist[i][j] = new_dist;
            }
        }
        // Sum of shortest distances for unordered pairs (i < j)
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                sum += dist[i][j];
            }
        }
        cout << sum << " ";
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
    //cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
