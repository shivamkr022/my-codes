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

int shortestPath(vector<vector<int>> &grid, pair<int, int> src, pair<int, int> des) {

        // ✅ Step 0: Edge case — if source is already destination
        if (src == des) return 0;

        int n = grid.size();
        int m = grid[0].size();

        // ✅ Step 1: Distance matrix initialized to infinity (1e9)
        vector<vector<int>> dis(n, vector<int>(m, 1e9));

        // ✅ Step 2: BFS queue storing {distance, {row, col}}
        queue<pair<int, pair<int, int>>> q;

        int row = src.first; 
        int col = src.second;

        // ✅ Step 3: Mark source distance as 0 and push to queue
        dis[row][col] = 0;
        q.push({0, {row, col}});

        // ✅ Step 4: Direction vectors for 4-directional movement
        int dr[] = {-1, 0, 1, 0}; // up, right, down, left
        int dc[] = {0, 1, 0, -1};

        // ✅ Step 5: Start BFS traversal
        while (!q.empty()) {
            auto ele = q.front();
            q.pop();
            int curr_dis = ele.first;
            int curr_row = ele.second.first;
            int curr_col = ele.second.second;

            // ✅ Step 6: Explore all 4 directions
            for (int i = 0; i < 4; i++) {
                int new_row = curr_row + dr[i];
                int new_col = curr_col + dc[i];

                // ✅ Step 7: Check bounds, cell must be valid and not visited in shorter path
                if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m &&
                    grid[new_row][new_col] == 1 && curr_dis + 1 < dis[new_row][new_col]) {

                    // ✅ Step 8: Update distance for neighbor cell
                    dis[new_row][new_col] = curr_dis + 1;

                    // ✅ Step 9: If destination found, return distance immediately
                    if (new_row == des.first && new_col == des.second) {
                        return curr_dis + 1;
                    }

                    // ✅ Step 10: Push the neighbor to queue for further BFS
                    q.push({curr_dis + 1, {new_row, new_col}});
                }
            }
        }

        // ✅ Step 11: Destination not reachable
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

