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

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout << "errr----  " << #x << " = " << x << endl
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
using namespace std;


void dfs(int row, int col, vector<string>& grid, vector<vector<int>>& vis, int& cnt) {
    
    if (cnt <= 0) return; // stop when we've kept required cells
    vis[row][col] = 1;
    cnt--;
    int n = grid.size();
    int m = grid[0].size();

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int new_row = row + dr[i];
        int new_col = col + dc[i];

        if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m &&
            grid[new_row][new_col] == '.' && vis[new_row][new_col] == 0) {
            dfs(new_row, new_col, grid, vis, cnt);
        }
    }
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    int total_empty = 0;
    for (int i = 0; i < n; i++) {
        for (char ch : grid[i]) {
            if (ch == '.') total_empty++;
        }
    }
    int cnt = total_empty - k; // we only keep cnt cells as reachable
    vector<vector<int>> vis(n, vector<int>(m, 0));

    bool started = false;
    for (int i = 0; i < n && !started; i++) {
        for (int j = 0; j < m && !started; j++) {
            if (grid[i][j] == '.') {
                dfs(i, j, grid, vis, cnt);
                started = true;
            }
        }
    }
    // Convert all unvisited '.' to 'X'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && vis[i][j] == 0) {
                grid[i][j] = 'X';
            }
        }
    }
    for (string row : grid) {
        cout << row << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
