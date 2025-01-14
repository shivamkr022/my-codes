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
    vector<int>brr(n);
    for(int i=0;i<n;i++) cin>>brr[i]; // input
    vector<int>crr(n);
    for(int i=0;i<n;i++) cin>>crr[i];

    vector<pair<int,int>>a;
    vector<pair<int,int>>b;
    vector<pair<int,int>>c;
    for(int i=0;i<n;i++){       // storing crr ele with their index
        a.push_back({arr[i],i});
    }
    for(int i=0;i<n;i++){ 
        b.push_back({brr[i],i});     // storing brr ele with their index
    }
    for(int i=0;i<n;i++){
        c.push_back({crr[i],i});       // storing crr ele with their index
    }
    sort(a.begin(),a.end(),greater<>());
    sort(b.begin(),b.end(),greater<>());
    sort(c.begin(),c.end(),greater<>());

    int ans =0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(a[i].second!=b[j].second and b[j].second!=c[k].second and c[k].second!=a[i].second){
                    ans=max(ans,a[i].first+b[j].first+c[k].first);
                }
            }
        }
    }
    cout<<ans<<endl;
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

