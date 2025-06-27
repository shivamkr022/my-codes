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

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int src[] ={0,0};
        int des[] ={n-1,n-1};

        if (grid[src[0]][src[1]] == 1 || grid[des[0]][des[1]] == 1)
            return -1;

        if (src[0] == des[0] && src[1] == des[1])
            return 1;

        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        
        queue<pair<int, pair<int, int>>> q;   // ({distance,{row,col}});
        
        int row = src[0]; 
        int col = src[1];

        if (grid[row][col] == 1 || grid[des[0]][des[1]] == 1)
            return -1; // start or end blocked

        dis[0][0] = 0;
        q.push({0, {row, col}});
        
        // Now 8 directions (4 + diagonals)
        int dr[] = {-1, -1, -1,  0, 0, 1, 1, 1};
        int dc[] = {-1,  0,  1, -1, 1, -1, 0, 1};
        
        while (!q.empty()) {
            auto ele = q.front();
            q.pop();
            int curr_dis = ele.first;
            int curr_row = ele.second.first;
            int curr_col = ele.second.second;
            
            for (int i = 0; i < 8; i++) {
                int new_row = curr_row + dr[i];
                int new_col = curr_col + dc[i];
                
                if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m &&
                    grid[new_row][new_col] == 0 && curr_dis + 1 < dis[new_row][new_col]) {
                    
                    dis[new_row][new_col] = curr_dis + 1;
                    
                    if (new_row == des[0] && new_col == des[1]) {
                        return curr_dis + 2;
                    }
                    
                    q.push({curr_dis + 1, {new_row, new_col}});
                }
            }
        }
        return -1;
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

