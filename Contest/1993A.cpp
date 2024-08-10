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
    string s;
    cin>>s;
    int n1=4*n;
    int aa=0;
    int bb=0;
    int cc=0;
    int dd=0;
    int q=0;
    for(int i=0;i<n1;i++){
        if(s[i]=='A'){
            aa++;
        }
        else if(s[i]=='B'){
            bb++;
        }
        else if(s[i]=='C'){
            cc++;
        }
        else if(s[i]=='D'){
            dd++;
        }
        else{
            q++;
        }
    }
    int ans =0;
    ans+=min(n,aa);
    ans+=min(n,bb);
    ans+=min(n,cc);
    ans+=min(n,dd);
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
   // t = 1;
    while(t--){
        solve();
    }
return 0;
}

