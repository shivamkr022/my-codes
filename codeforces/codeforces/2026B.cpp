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
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    if(n==1){
        cout<<1<<endl;
        return;
    }
    if(n%2==0){
        int ans =arr[1]-arr[0];
        for(int i=2;i<n;i+=2){
            ans = max(ans,abs(arr[i]-arr[i+1]));
        }
        cout<<ans<<endl;
    }
    else{
        int ans = 1e18;
        for(int i=0;i<n;i++){
            vector<int>v;
            for(int j=0;j<n;j++){
                if(j==i){
                    continue;
                }
                v.push_back(arr[j]);
            }
            int mxm = v[1]-v[0];
            for(int j=2;j<n-1;j+=2){
                mxm = max(mxm,v[j+1]-v[j]);
            }
            ans = min(ans,mxm);
        }     
        cout<<ans<<endl; 
    }
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
   // t = 1;
    while(t--){
        solve();
    }
return 0;
}

