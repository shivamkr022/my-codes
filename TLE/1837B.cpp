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

    int c1=0; // its for max no of greater than char // '>' currently
    int c2=0; // its for max no of greater than char // '<' currently
    int m1=0; // its for max no of greater than char // '>' overall
    int m2=0; // its for max no of greater than char // '<' overall

    for(int i=0;i<n;i++){
        if(s[i]=='>'){
         c1++;
        m1=max(c1,m1);
        }                // normal code for finding max subsequence
        else{
            c1=0;
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]=='<'){
         c2++;                    // normal code for finding max subsequence
        m2=max(c2,m2);
        }
        else{
            c2=0;
        }
    }
    int maxm = max(m1,m2); // answer
    cout<<(maxm+1)<<endl;

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

