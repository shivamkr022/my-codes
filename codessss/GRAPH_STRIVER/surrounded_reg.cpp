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

   void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>& arr, int drow[],int dcol[]){
        int n = arr.size();
        int m = arr[0].size();

        vis[row][col]=1;

        for(int i=0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow>=0 and ncol >=0 and nrow < n and ncol < m and !vis[nrow][ncol]and arr[nrow][ncol]=='O'){
                dfs(nrow,ncol,vis,arr,drow,dcol);
            }
        }
   }
/* write core logic here */
void solve(){
    // vector<vector<int>>arr;
    //     int n = arr.size();
    //     int m = arr[0].size();
    //     int drow[]= {-1,0,1,0};
    //     int dcol[] = {0,1,0,-1};
    //     vector<vector<int>>vis(n,vector<int>(m,0));

    //     for(int i=0;i<n;i++){
    //         if(!vis[i][0] and arr[i][0]=='O'){ // 1st col traversal
    //             dfs(i,0,vis,arr,drow,dcol);
    //         }
    //         if(!vis[i][m-1] and arr[i][m-1]=='O'){ // last col traversal
    //             dfs(i,m-1,vis,arr,drow,dcol);
    //         }
    //     }

    //     for(int j=0;j<m;j++){
    //         if(!vis[0][j] and arr[0][j]=='O'){
    //             dfs(0,j,vis,arr,drow,dcol);
    //         }
    //         if(!vis[n-1][j] and arr[n-1][j]=='O'){
    //             dfs(n-1,j,vis,arr,drow,dcol);
    //         }
    //     }
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(!vis[i][j] and arr[i][j]=='O'){
    //                 arr[i][j]='X';
    //             }
    //         }
    //     }
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

