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
  
      void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int drow[], int dcol[]) {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, grid, vis, drow, dcol);
            }
        }
    }
    
/* write core logic here */
void solve(){
        //   int n = grid.size();
        // int m = grid[0].size();
        // vector<vector<int>> vis(n, vector<int>(m, 0));
        // int drow[] = {-1, 0, 1, 0};
        // int dcol[] = {0, -1, 0, 1};

        // for (int i = 0; i < n; i++) {
        //     if (grid[i][0] == 1 and !vis[i][0]) {
        //         dfs(i, 0, grid, vis, drow, dcol);
        //     }
        //     if (grid[i][m-1] == 1 and !vis[i][m-1]) {
        //         dfs(i, m-1, grid, vis, drow, dcol);
        //     }
        // }
        // for (int j = 0; j < m; j++) {
        //     if (grid[0][j] == 1 and !vis[0][j]) {
        //         dfs(0, j, grid, vis, drow, dcol);
        //     }
        //     if (grid[n-1][j] == 1 and !vis[n-1][j]) {
        //         dfs(n-1, j, grid, vis, drow, dcol);
        //     }
        // }

        // int ans = 0;
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         if (!vis[i][j] && grid[i][j] == 1) {
        //             ans++;
        //         }
        //     }
        // }
        // return ans;  
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

