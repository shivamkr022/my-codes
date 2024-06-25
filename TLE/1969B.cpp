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
    vector<int>arr(n);      // input
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int c1=0;
    int c2=0;
    int c3=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0) c1++; // count no of zeroes
    }
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
             c2++;
        c3=max(c3,c2); // length of longest non-zero subseq
        }
        else{
            c2=0;
        }
    }
    if(n==c1) cout<<0<<endl;
    else if(c1+c3<n) cout<<2<<endl; // aq to question
    else if(c1+c3==n) cout<<1<<endl;
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
   // t = 1;
    while(t--){
        solve();
    }
return 0;
}