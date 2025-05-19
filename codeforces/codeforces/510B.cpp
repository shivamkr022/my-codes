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
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << endl
#define print(v) do { \
    cerr << "vect--" << #v << " = [ "; \
    for (int i = 0; i < v.size(); i++) cerr << v[i] << " "; \
    cerr << " ]" << endl; \
} while(0)
#else
#define debug(x)
#define print(v)
#endif

#define endl "\n"
#define int long long
#define mod 1000000007

int n, m;
vector<vector<char>> arr;
vector<vector<int>> vis;
int drow[] = {-1, 0, 1, 0};
int dcol[] = {0, -1, 0, 1};

bool dfs(int row, int col, int pr, int pc, char color, int depth) {
    vis[row][col] = 1;
    for(int i = 0; i < 4; i++) {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m) {
            if (arr[nrow][ncol] != color) continue;
            if (!vis[nrow][ncol]) {
                if (dfs(nrow, ncol, row, col, color, depth + 1)) return true;
            }
            else if (nrow != pr || ncol != pc) {
                if (depth >= 4) return true; // valid cycle
            }
        }
    }
    return false;
}

void solve() {
    cin >> n >> m;
    arr.assign(n, vector<char>(m));
    vis.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    bool found = false;
    for (int i = 0; i < n && !found; i++) {
        for (int j = 0; j < m && !found; j++) {
            if (!vis[i][j]) {
                if (dfs(i, j, -1, -1, arr[i][j], 1)) {
                    found = true;
                }
            }
        }
    }

    cout << (found ? "Yes" : "No") << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
