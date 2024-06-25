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

string LCS(string X, string Y, int m, int n){
    int maxlen = 0;         // stores the max length of LCS
    int endingIndex = m;    // stores the ending index of LCS in `X`
 
    int lookup[m + 1][n + 1];
 
    // initialize all cells of the lookup table to 0
    memset(lookup, 0, sizeof(lookup));
 
    // fill the lookup table in a bottom-up manner
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            // if the current character of `X` and `Y` matches
            if (X[i - 1] == Y[j - 1]){
                lookup[i][j] = lookup[i - 1][j - 1] + 1;
 
                // update the maximum length and ending index
                if (lookup[i][j] > maxlen){
                    maxlen = lookup[i][j];
                    endingIndex = i;
                }
            }
        }
    }
 
    // return longest common substring having length `maxlen`
    return X.substr(endingIndex - maxlen, maxlen);
}

/* write core logic here */
void solve(){
string X,Y;
        cin>>X>>Y;
        int m = X.size(), n = Y.size();
        string ans=LCS(X, Y, m, n);
        int ok=ans.size();
        int c=(m-ok)+(n-ok);
        cout<<c<<"\n";
    
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

