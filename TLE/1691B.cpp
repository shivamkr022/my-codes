// /*
//   ------------------------------------------
//  |                                        |
//  |      Code Crafted by Shivam     |
//  |                                        |
//   ------------------------------------------
//     \        ,     ,        /
//       \      |     |      /
//          \   \_/   /
//            \  -----  /
//              \_/
  
//   Happy coding! 
// */

// /* includes and all */

// #include<bits/stdc++.h>
// #ifndef ONLINE_JUDGE
// #define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
// #define print(v) do { \
//                     cout << "vect--" << #v << " = [ "; \
//                     for (int i = 0; i < v.size(); i++) { \
//                         cout << v[i] << " "; \
//                     } \
//                     cout << " ]" << endl; \
//                 } while(0)
// #else
// #define debug(x)
// #define print(v)
// #endif
// #define endl "\n"
// #define int long long int
// #define mod 1000000007
// #define mn(a,b,c) min(a,min(b,c))
// #define mx(a,b,c) max(a,max(b,c))
// using namespace std;

// /* write core logic here */
// void solve(){
//     int n;
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int maxx =arr[n-1];
//     vector<int>ans(n);
//     ans[0]=2;
//     ans[1]=1;
//         for(int i=0;i<n;i++){
//             ans.push_back(i+1);
//         }
//     if(maxx<=n){
//         for(int i=0;i<n;i++){
//             cout<<ans[i]<<" ";
//         }
//          cout << endl; 
//     }
//     else{
//     cout<<-1<<endl;
//     }
// }
// /* logic ends */

// signed main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     #ifndef ONLINE_JUDGE
//         freopen("Error.txt" , "w" , stderr);
//     #endif
//     int t;
//     cin>>t;
//     //t = 1;
//     while(t--){
//         solve();
//     }
// return 0;
// }
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
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    
    int maxx = arr[n-1];
    vector<int> ans(n);
    
    // Initialize the ans vector with correct values
    if (n >= 2) {
        ans[0] = 5;
        ans[1] = 1;
        for(int i = 2; i < n; i++) {
            ans[i] = i ;
        }
    } 
    else {
        ans[0] = 1; // Handle the case when n == 1
    }
    
    if(maxx <= n){
        for(int i = 0; i < n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    } 
    else {
        cout << -1 << endl;
    }
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

