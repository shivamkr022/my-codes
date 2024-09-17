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
int findSquareRoot(int num) {
    if (num < 0) return -1;  // Negative numbers can't be perfect squares

    int root = static_cast<int>(sqrt(num));
    if (root * root == num) {
        return root;  // Return the square root if it's a perfect square
    } else {
        return -1;  // Return -1 if it's not a perfect square
    }
}

/* write core logic here */
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ss =findSquareRoot(n);
    debug(ss);
    int zz =0;
    int req = (ss-2)*(ss-2);

    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            zz++;
        }
    }

    if(ss!=-1 and req==zz){
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

