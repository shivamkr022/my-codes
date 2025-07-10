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

// BFS function
int bfs(const vector<vector<char>>& grid, pair<int,int> &start, pair<int,int> &tar,
    queue<tuple<int, int, int, int, int>> &q, vector<int>&vis){

    int n = grid.size(), m = grid[0].size();
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    // visited[x][y][dir][len]
    vector<vector<vector<vector<bool>>>> visited(n, vector<vector<vector<bool>>>(m, vector<vector<bool>>(4, vector<bool>(4, false))));

    while (!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int steps = get<2>(q.front());
        int dir = get<3>(q.front());
        int len = get<4>(q.front());
        q.pop();

        if (make_pair(x, y) == tar) return steps;

        if (visited[x][y][dir][len]) continue;
        visited[x][y][dir][len] = true;

        for (int ndir = 0; ndir < 4; ndir++) {
            int nx = x + dx[ndir];
            int ny = y + dy[ndir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (grid[nx][ny] == '#') continue;

            if (ndir == dir && len < 3 && !visited[nx][ny][ndir][len + 1]) {
                q.push(make_tuple(nx, ny, steps + 1, ndir, len + 1));
            } 
            else if (ndir != dir && !visited[nx][ny][ndir][1]) {
                q.push(make_tuple(nx, ny, steps + 1, ndir, 1));
            }
        }
    }

    return -1;
}

/* write core logic here */
void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    pair<int, int> start, tar;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'S'){
               start = {i, j};
            }
            if(grid[i][j] == 'T') {
               tar = {i, j};
            }
        }
    }

    queue<tuple<int, int, int, int, int>> q;
    vector<int>vis(n,0); // unused placeholder

    vector<int> dx = {-1, 1, 0, 0}; // up, down, left, right
    vector<int> dy = {0, 0, -1, 1};

    int sx = start.first;
    int sy = start.second;

    for(int dir = 0; dir < 4; dir++) {
        int nx = sx + dx[dir];
        int ny = sy + dy[dir];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#') {
            q.push(make_tuple(nx, ny, 1, dir, 1));
        }
    }

    int ans = bfs(grid, start, tar, q, vis);
    cout << ans << endl;
}

/* main */
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    //cin >> t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}
