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
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;  
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

/* write core logic here */
void solve(){
    int n,k;
    cin>>n>>k;
    if(n<=k){
        cout<<1<<endl;
        return;
    }
    if(k==1){
        cout<<n<<endl;
        return;
    }
    if(isPrime(n) and n!=k){
        cout<<n<<endl;
        return;
    }
    int ans =n;
	for (int j = 1; j * j <= n; j++) {
        if (n % j == 0) {
            if (j <= k) {
                ans = min(ans, n / j);
            }
            if (n / j <= k) {
                ans = min(ans, j);
            }
        }
    }
    cout << ans << endl;
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

