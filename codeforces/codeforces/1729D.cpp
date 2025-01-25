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
    cin >> n;
    vector<int>x(n), y(n);
    vector<pair<int, int>>dif(n);

    for(auto &i : x) cin >> i;
    for(auto &i: y) cin >> i;
    for(int i = 0; i < n; i++){
       //dif.push_back({(y[i] - x[i]),i});
         dif[i].first = y[i] - x[i];
         dif[i].second = i;
    }
    sort(dif.begin(), dif.end(),greater<>());
    int j = n - 1, cnt = 0;
    for(int i = 0; i < n; i++){
        while(j > i && dif[i].first + dif[j].first < 0) j--;
        if(j <= i) break;
        cnt++;
         j--;
    }
    cout << cnt << endl;
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

