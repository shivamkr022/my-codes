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
struct Laptop {
    int price, quality;
};

// Custom comparator: sort by price
bool cmp(const Laptop& x, const Laptop& y) {
    return x.price < y.price;
}
/* write core logic here */
void solve(){
    int n;
    cin >> n;
    vector<Laptop> pr(n);

    for (int i = 0; i < n; ++i)
        cin >> pr[i].price >> pr[i].quality;

    sort(pr.begin(), pr.end(), cmp);

    for (int i = 0; i < n - 1; ++i) {
        if (pr[i].quality > pr[i + 1].quality) {
            cout << "Happy Alex" << endl;
            return ;
        }
    }
    cout << "Poor Alex" << endl;
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

