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
pair<int, int> find_max_sorted_interval(const vector<int> &arr) {
    int n = arr.size();
    if (n == 0) return {-1, -1};

    int max_length = 1;  // Minimum length of a sorted subarray
    int max_start = 0, max_end = 0;
    int start = 0;

    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[i - 1]) { // The sorted interval ends at i-1
            int length = i - start;
            if (length > max_length) {
                max_length = length;
                max_start = start;
                max_end = i - 1;
            }
            start = i; // Start a new interval from the current element
        }
    }

    if (n - start > max_length) {   // Final check for the last subarray
        max_start = start;
        max_end = n - 1;
    }

    return {max_start, max_end};
}

/* write core logic here */
void solve(){
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
   auto result = find_max_sorted_interval(b);
    cout << (result.first+1) << " " << (result.second+1) << endl;

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

