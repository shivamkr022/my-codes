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

int get(const vector<int>& arr, int start,int k) { // fn to return res
 int res= 0;
 for (int i = start; i<start+k; i++) {
        res |= arr[i];
 }
    return res;
}

int smallestK(const vector<int>& arr) {  // fn to return k
 int n = arr.size(); 
 for (int k = 1; k <= n; ++k) {
  int OR = get(arr, 0, k);
      bool valid = true;
 
      for (int i = 1; i <= n-k; ++i) {
       if (get(arr, i, k) !=OR) {
           valid = false;
          break;
        }
     } 
    if (valid) {
    return k;
    }
 }
  return n;
}

/* write core logic here */
void solve(){
     int n; 
    cin >> n;  // taking input
   vector<int> a(n);
   for(int i=0;i<n;i++) cin >> a[i];
 int res=smallestK(a);
 cout <<res<<endl;
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

