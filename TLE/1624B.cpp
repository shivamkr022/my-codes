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
    int a, b, c;
    cin >> a >> b >> c;

    int new_a = b - (c - b);
    if(new_a >= a && new_a % a == 0 && new_a != 0) {
        cout << "YES\n";
        return;
    }

    int new_b = a + (c - a)/2;
    if(new_b >= b && (c-a)%2 == 0 && new_b % b == 0 && new_b != 0) {
        cout << "YES\n";
        return;
    }

    int new_c = a + 2*(b - a);
    if(new_c >= c && new_c % c == 0 && new_c != 0) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
    return;
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

