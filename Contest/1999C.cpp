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
    int x,y,z;
    cin>>x>>y>>z;
    vector<pair<int,int>>mp;
    for(int i=1;i<=x;i++){
        int a,b;
        cin>>a>>b;
        mp.push_back({a,b});
    }
    sort(mp.begin(),mp.end());
    int shower =mp[0].first;
    if(shower>=y){
        cout<<"YES"<<endl;
        return;
    }
    int notshower = mp[0].second;
    for(int k=1;k<x;k++){
        if(mp[k].first>notshower){
            if(mp[k].first-notshower>=y){
                cout<<"YES"<<endl;
                return;
            }
        }
        notshower=max(notshower,mp[k].second);
    }
    if(z-notshower>=y){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
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

