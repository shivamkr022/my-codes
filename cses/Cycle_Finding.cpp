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
#define print(v)                                      \
    do {                                              \
        cout << "vect--" << #v << " = [ ";            \
        for (int i = 0; i < v.size(); i++) {          \
            cout << v[i] << " ";                      \
        }                                             \
        cout << " ]" << endl;                         \
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
    int n, m;
    cin >> n >> m;

    vector<pair<pair<int, int>, int>> edges;

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({{u, v}, w});
    }

    const int INF = 1e18;
    vector<int> dist(n + 1, 0);
    vector<int> parent(n + 1, -1);
    int x = -1;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < edges.size(); j++) {
            int u = edges[j].first.first;
            int v = edges[j].first.second;
            int w = edges[j].second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    for (int j = 0; j < edges.size(); j++) {
        int u = edges[j].first.first;
        int v = edges[j].first.second;
        int w = edges[j].second;

        if (dist[u] + w < dist[v]) {
            parent[v] = u;
            x = v;
            break;
        }
    }

    if (x == -1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;

        int y = x;
        for (int i = 1; i <= n; i++) {
            y = parent[y];
        }

        vector<int> cycle;
        int cur = y;
        do {
            cycle.push_back(cur);
            cur = parent[cur];
        } while (cur != y);
        cycle.push_back(y);

        reverse(cycle.begin(), cycle.end());

        for (int node : cycle) {
            cout << node << " ";
        }
        cout << endl;
    }
}
/* logic ends */

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    int t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
