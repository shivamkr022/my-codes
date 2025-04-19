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
int k1(vector<int>& arr) {
    int n = arr.size();           /// kadanes algo
    int max_sum = arr[0];
    int current_sum = arr[0];
    
    for (int i = 1; i < n - 1; i++) {
        current_sum = max(arr[i], current_sum + arr[i]);
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}
int k2(vector<int>& arr) {
    int n = arr.size();
    int max_sum = arr[1];
    int current_sum = arr[1];        /// kadanes algo
    
    for (int i = 2; i < n; i++) {
        current_sum = max(arr[i], current_sum + arr[i]);
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}

/* write core logic here */
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int y =0;
    for(int ele:arr){
        y+=ele;
    }
    int mm = *max_element(arr.begin(),arr.end());
    if(y<=mm){
        cout<<"NO"<<endl;
        return;
    }
    int mm1 = k1(arr);
    int mm2 = k2(arr);
    int lol = max(mm1,mm2);

    if(lol>=y){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
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

