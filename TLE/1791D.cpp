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
    string s;   // input
    cin>>s;

    set<char>s1,s2;      // to store the unique elements
    vector<int> prefix(n,0),suffix(n,0);
    for(int i=0;i<n;i++){
        s1.insert(s[i]);
        prefix[i]=s1.size();
    }
    for(int i=n-1;i>=0;i--){
        s2.insert(s[i]); 
        suffix[i]=s2.size();
    }
    int maxx=0;
    int ans =0;
    for(int i=0;i<n-1;i++){
        ans = prefix[i]+suffix[i+1];
       maxx= max(maxx ,ans);
    }
    cout<<maxx<<endl;
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

