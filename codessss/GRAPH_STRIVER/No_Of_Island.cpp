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
void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&arr){
    int n = arr.size();
    int m = arr[0].size();
    if (row < 0 || row >= n || col < 0 || col >= m || arr[row][col] == '#' || vis[row][col]) {
        return;
    }
    vis[row][col] = 1;  // mark visited

    // Explore all 4 directions
    dfs(row + 1, col, vis, arr); // down
    dfs(row - 1, col, vis, arr); // up
    dfs(row, col + 1, vis, arr); // right
    dfs(row, col - 1, vis, arr); // left      
}

/* write core logic here */
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>arr(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    if(arr.size() == 0) {
        cout << 0 << endl;
        return;
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int ans = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if(arr[r][c] == '.' && vis[r][c] == 0){
                ans++;
                dfs(r, c, vis, arr);
            }
        }
    }
    cout << ans << endl;
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

//  BFS SOLUTION

    // void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     queue<pair<int, int>> q;
    //     q.push({row, col});
    //     vis[row][col] = true;

    //     // directions: up, down, left, right
    //     int dx[] = {-1, 1, 0, 0};
    //     int dy[] = {0, 0, -1, 1};

    //     while (!q.empty()) {
    //         auto [x, y] = q.front(); q.pop();

    //         for (int d = 0; d < 4; d++) {
    //             int nx = x + dx[d];
    //             int ny = y + dy[d];

    //             if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
    //                 !vis[nx][ny] && grid[nx][ny] == '1') {
    //                 vis[nx][ny] = true;
    //                 q.push({nx, ny});
    //             }
    //         }
    //     }
    // }

    // int numIslands(vector<vector<char>>& grid) {
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     vector<vector<bool>> vis(n, vector<bool>(m, false));
    //     int islands = 0;

    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < m; j++) {
    //             if (grid[i][j] == '1' && !vis[i][j]) {
    //                 islands++;
    //                 bfs(i, j, grid, vis);
    //             }
    //         }
    //     }
    //     return islands;
    // }
