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
//     int count=0;
//     vector<int>ans;
//     for(int i=0;i<n;i++){
//         ans.push_back(i+1+arr[i]);
//     }
//     int fans=0;
//     sort(ans.begin(),ans.end());
//     for(int i=1;i<ans.size();i++){
//         if(ans[i-1]==ans[i]){
//              count++;
//         }
//     }
//     if(count>=1) cout<<2<<endl;
//     else cout<<3<<endl;
//  }
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
    cin>>n;
    vector<int>arr(n);
    int count=0;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
      cin>>arr[i];
      mp[arr[i]]=i+1;
      if(mp[i+1]==arr[i]){
        count=1;
      }
    }
    if(count){
      cout<<2<<endl;
    }
    else{
      cout<<3<<endl;
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

