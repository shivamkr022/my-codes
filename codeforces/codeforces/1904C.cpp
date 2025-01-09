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
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    if(k>=3){
        cout<<0<<endl;
        return;
    }
    sort(arr.begin(),arr.end());
    int temp=INT_MAX;
    // for(int i=1;i<n;i++){
    //     temp=min(temp,(arr[i]-arr[i-1]));
    // }
    // if(k==1){
    //     cout<<temp<<endl;
    //     return;
    // }
    int d=arr[0];
       // int d = a[0];
    for (int i = 0; i < n - 1; i++) d = min(d, arr[i + 1] - arr[i]);
       if (k == 1) {
            cout << d << endl;
            return;
        }
    for (int i = 0; i < n; i++){
           for (int j = 0; j < i; j++) {
            int v = arr[i] - arr[j];
            int p = lower_bound(begin(arr), end(arr), v) - begin(arr);
            if (p < n) d = min(d, arr[p] - v);
            if (p > 0) d = min(d, v - arr[p - 1]);
        }
    }
    cout<<d<<endl;
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

