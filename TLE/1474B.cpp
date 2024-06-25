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
const int MAX = 1000000;
using namespace std;
vector<int> pp;

void sievetheorem() {
    vector<bool> prime(MAX + 1, true); // initially we mark all value prime
    for (int i = 2; i * i <= MAX; i++) {
        if (prime[i] == true) {
            for (int j = 2 * i; j <= MAX; j += i) {
                prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= MAX; i++) {
        if (prime[i] == true)
            pp.push_back(i);
    }
}

/* write core logic here */
void solve() {
    int d;
    cin >> d;
    int p1 = *lower_bound(pp.begin(), pp.end(), 1 + d);
    int p2 = *lower_bound(pp.begin(), pp.end(), p1 + d);
    
    cout << p1 * p2 << endl;
}
/* logic ends */

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif

    sievetheorem(); // Initialize the sieve to compute primes
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
