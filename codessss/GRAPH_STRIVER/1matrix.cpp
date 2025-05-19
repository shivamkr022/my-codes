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

 vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>ans(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q; // to store {{nrow,ncol},distance}
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({{i,j},0}); // 1 ka dist 0 hoga 1 se always
                    vis[i][j]=1;
                }
                else{
                    vis[i][j]=0; // starting point 1 hoga only  thats why we push only 1 in the queue
                }
            }
        }
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        while(!q.empty()){
            
            int row = q.front().first.first;  // stored in queue
            int col = q.front().first.second;
            int dis = q.front().second;
            q.pop();  // store and pop
            
            ans[row][col] = dis;  // dis matrix m answer store 
            
            for(int i=0;i<4;i++){
                int nrow  = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow>=0 and nrow <n and ncol >=0 and ncol <m and vis[nrow][ncol]==0){ // boundary condn and not visited yet
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},dis+1});
                    
                }
            }
        }
        return ans ;  
    }
/* write core logic here */
void solve(){

    //----->>>>> INPUT
    
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

