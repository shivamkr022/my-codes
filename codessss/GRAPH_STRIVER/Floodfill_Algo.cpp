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

    void dfs(int sr,int sc,int color,int startColor,vector<vector<int>>&image,vector<vector<int>>&vis){
        int n = image.size();
        int m = image[0].size();
        if (sr < 0 || sr >= n || sc < 0 || sc >= m) return;
        if (vis[sr][sc] || image[sr][sc] != startColor) return;
        vis[sr][sc]=1;
        image[sr][sc]=color;
        dfs(sr+1,sc,color,startColor,image,vis);
        dfs(sr-1,sc,color,startColor,image,vis);
        dfs(sr,sc+1,color,startColor,image,vis);
        dfs(sr,sc-1,color,startColor,image,vis);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startColor = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> arr = image;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        if (startColor == color) return image;
        dfs(sr, sc, color, startColor, image, vis);
        return image;
    }

/* write core logic here */
void solve(){

    /////----------->>>>>>>> INPUT
    
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

