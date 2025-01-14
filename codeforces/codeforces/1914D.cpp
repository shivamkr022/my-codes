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
vector<int> get_best3(const vector<int>& arr) {
    vector<int> indices = {-1, -1, -1}; // Store indices of the three largest elements
    for (int i = 0; i < arr.size(); i++) {
        if (indices[0] == -1 || arr[i] > arr[indices[0]]) {
            indices[2] = indices[1];
            indices[1] = indices[0];
            indices[0] = i;
        } else if (indices[1] == -1 || arr[i] > arr[indices[1]]) {
            indices[2] = indices[1];
            indices[1] = i;
        } else if (indices[2] == -1 || arr[i] > arr[indices[2]]) {
            indices[2] = i;
        }
    }
    return indices;
}

/* write core logic here */
void solve(){
    int n;
    cin>>n;
    vector<int>ar(n);
    for(int i=0;i<n;i++) cin>>ar[i];
    vector<int>brr(n);
    for(int i=0;i<n;i++) cin>>brr[i];
    vector<int>crr(n);
    for(int i=0;i<n;i++) cin>>crr[i];

    int ans =0;
    vector<int> best_a = get_best3(ar);
    vector<int> best_b = get_best3(brr);
    vector<int> best_c = get_best3(crr);

    for (int i : best_a) {
        for (int j : best_b) {
            for (int k : best_c) {
                if (i != j && j != k && k != i) {
                    int sum = ar[i] + brr[j] + crr[k];
                    ans = max(ans, sum); 
                }
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
