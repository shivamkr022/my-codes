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

class Solution {
public:
    bool dfs(int row,int col , vector<vector<int>>& grid , vector<vector<int>>&vis , int health ){

        int n  = grid.size();
        int m = grid[0].size();

        if(grid[row][col] == 1) health--;

        if(health < 1) return false;

        if(row == n-1 && col == m-1) return true; 
        
        if(vis[row][col] >= health) return false;
        vis[row][col] = health;

        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};

        for(int i=0;i<4;i++){
            int new_row = row + dr[i];
            int new_col = col + dc[i];

            if(new_row < 0 || new_row >= n || new_col < 0 || new_col >= m) continue;

            if(dfs(new_row, new_col, grid, vis, health)) return true;
        }
        return false;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1));
        return dfs(0, 0, grid, vis, health);
    }
};

/* write core logic here */
void solve(){
    
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

