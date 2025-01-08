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
    string s;
    cin>>s;
    int r = 0;
    int l = 0;
    int d = 0;
    int u = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='R') r++;
        if(s[i]=='L') l++;
        if(s[i]=='U') u++;
        if(s[i]=='D') d++;
    }
    // debug(r);
    // debug(l);
    // debug(u);
    // debug(d);
    if(s.length()%2!=0){
        cout<<-1<<endl;
        return;
    }
    int lr = abs(r-l);
    int ud = abs(u-d);
    cout<<(lr+ud)/2<<endl;
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

