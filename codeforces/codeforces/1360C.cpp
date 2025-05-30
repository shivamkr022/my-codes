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
    int x=0;
    int y=0;
    for(int i=0;i<n;i++){
        if(arr[i]%2==0) x++;
        else y++;
    }
    if(x%2==0 and y%2==0){
        cout<<"YES"<<endl;
        return;
    }
    sort(arr.begin(),arr.end());
    int diff =0;
    for(int i=1;i<n;i++){
        if(arr[i]-arr[i-1]==1){
            diff++;
        }
    }
    if(diff==0 and (x%2==1 or y%2==1)){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    // debug(x);
    // debug(y);
    // debug(diff);
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

