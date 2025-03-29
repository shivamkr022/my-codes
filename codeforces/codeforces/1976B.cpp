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
    int k = n+1;
    vector<int>brr(k);
    for(int i=0;i<k;i++) cin>>brr[i];
    int xx = brr[k-1];
    int ans =0;
    for(int i=0;i<n;i++){
        ans+=abs(arr[i]-brr[i]);
    }
   // debug(xx);
    bool flag = false;
    for(int i=0;i<n;i++){
        if((arr[i]>=xx and brr[i]<=xx) or (arr[i]<=xx and brr[i]>=xx) ){
            flag = true;
            break;
        }
    }
    if(flag){
        cout<<(ans+1)<<endl;
        return;
    }
    int ss =1e18;
    for(int i=0;i<n;i++){
        ss=min(ss,abs(xx-arr[i]));
        ss=min(ss,abs(xx-brr[i]));
    }
    // debug(ans);
    // debug(ss);
    cout<<(ans+ss+1)<<endl;
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