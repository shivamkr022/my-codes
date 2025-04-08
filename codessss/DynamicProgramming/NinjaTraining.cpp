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

/* write core logic here */
void solve(){
    int n;
    cin>>n;
    int m=3;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){  
            cin>>arr[i][j];
        }
    }

    vector<vector<int>>dp(n,vector<int>(4,0)); // init dp vector

    dp[0][0] = max(arr[0][1],arr[0][2]);
    dp[0][1] = max(arr[0][2],arr[0][0]);         //// base case 
    dp[0][2] = max(arr[0][1],arr[0][0]);
    dp[0][3] = mx(arr[0][0],arr[0][2],arr[0][1]);

    for(int day =1;day<n;day++){  // day of activity
        for(int last =0;last<4;last++){   // which was the last activivity we have done
            dp[day][last]=0;
            for(int task=0;task<3;task++){  // which task we can do now
                if(task!=last){
                    int points = arr[day][task] + dp[day - 1][task]; // arr[day][task] // points for curr day
                    dp[day][last] = max(dp[day][last], points);   // dp[day-1][last] pre computed values till yesterday
                }
            }
        }
    }
    cout<<dp[n-1][3]<<endl;
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

