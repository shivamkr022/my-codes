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
bool f(int n,int m,vector<vector<char>>&arr,char ch){
    bool flag = false;
    for(int i=0;i<n;i++){
        if(arr[i][0]==ch){
            flag=true;
            break;               // check 1st column
        }
    }
    if(!flag) return false;
    flag = false;

    for(int i=0;i<n;i++){
        if(arr[i][m-1]==ch){   // checking last column
            flag=true;
            break;
        }
    }
    if(!flag) return false;
    flag = false;

    for(int j=0;j<m;j++){
        if(arr[0][j]==ch){       /// checking 1st row
            flag=true;      
            break;
        }
    }
    if(!flag) return false;
    flag = false;

    for(int j=0;j<m;j++){
        if(arr[n-1][j]==ch){   // checking last row
            flag=true;
            break;
        }
    }
    if(!flag) return false;
    flag = false;
    return true;
}

/* write core logic here */
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>arr(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    bool ans = f(n,m,arr,'W') || f(n,m,arr,'B');
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

