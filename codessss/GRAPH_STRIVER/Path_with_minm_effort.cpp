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

/*
   ---------------------------------------------
   |        Dijkstra's Algorithm (Grid)        |
   ---------------------------------------------
   Steps:
   1. Use a min-heap (priority queue) to always pick the path with the smallest "effort" so far.
   2. Effort is defined as the maximum absolute height difference along the current path.
   3. Use a 2D distance array to store the minimum effort required to reach each cell.
   4. Traverse in all 4 directions.
   5. For each neighbor, calculate the new effort = max(previous effort, current height diff).
   6. If this new effort is smaller, update the distance and push into the heap.
   7. When you reach the bottom-right cell, return the minimum effort required.
*/

int minimumEffortPath(vector<vector<int>>& arr) {
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> dis(n, vector<int>(m, 1e9));

    // Min-heap: {effort, {row, col}}
    priority_queue<pair<int, pair<int, int>>, 
                   vector<pair<int, pair<int, int>>>, 
                   greater<pair<int, pair<int, int>>>> pq;

    dis[0][0] = 0;
    pq.push({0, {0, 0}});

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while (!pq.empty()) {
        auto ele = pq.top();
        pq.pop();

        int prev_dis = ele.first;              // current effort so far
        int row = ele.second.first;
        int col = ele.second.second;

        if (row == n - 1 && col == m - 1)       // reached destination
            return prev_dis;

        for (int i = 0; i < 4; i++) {
            int new_row = row + dr[i];
            int new_col = col + dc[i];

            if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m) {
                int diff = abs(arr[row][col] - arr[new_row][new_col]);
                int effort = max(diff, prev_dis);  // new path effort

                if (dis[new_row][new_col] > effort) {
                    dis[new_row][new_col] = effort;
                    pq.push({effort, {new_row, new_col}});
                }
            }
        }
    }
    return 0; // unreachable
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

