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
    int n,p;
    cin>>n>>p;
    vector<int>a(n);
    vector<int>b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];   // no of person
    }
    for(int i=0;i<n;i++){
        cin>>b[i];    // cost
    }
   vector<pair<int,int> > mp;
    for(int i=0;i<n;i++){
        mp.push_back({min(p,b[i]),a[i]});
    }

    sort(mp.begin(),mp.end());
    
    int ans = p;
    int rem=n-1;
    for (int i=0;i<n-1;++i) {
      ans+=min(rem,mp[i].second)*mp[i].first;
      rem-=min(rem,mp[i].second);
    }
    cout << ans << '\n';
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

