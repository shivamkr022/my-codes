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

int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;
        int count = 1;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int new_row = row + dr[i];
            int new_col = col + dc[i];

            if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m &&
                !vis[new_row][new_col] && grid[new_row][new_col] == 1) {

                count += dfs(new_row, new_col, grid, vis); 
                // adds area from connected land.
                // e.g., if (0,0)=1 and its neighbor (0,1)=1, both unvisited,
                // dfs(0,0) will call dfs(0,1) and return 1 + 1 = 2
            }
        }

        return count;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int area = dfs(i, j, grid, vis);
                    ans = max(ans, area);
                }
            }
        }

        return ans;
    }

/* write core logic here */
void solve(){

    // INPUT
    
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

