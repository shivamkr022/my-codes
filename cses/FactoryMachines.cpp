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
    int n,t;
    cin>>n>>t;  // input
    vector<int>times(n);
    for(int i=0;i<n;i++) cin>>times[i];  // input of time taken by machine  
   
    int lo=0;
    int hi=1e18;
    int ans =1e18;     // using binary search method

    while(lo<=hi){
        int mid =(lo+hi)/2;
        int no_of_products = 0;
        for(int i=0;i<n;i++){
        no_of_products+= min(mid/times[i],(int)1e9); // no of products // t <=1e9 , no of products can exceed 1e9
        }
        
        if(no_of_products>=t){
            if(mid<ans)  // we need min time thats why we are checking this case // lik
            ans=mid;      // for this 3 7 , 3 2 5  // in 10 min also we can make 7 products or more // but thats not correct thats why we have to update the value
            hi=mid-1;
        }
        else
        lo = mid+1;  // just normla bs
    }
    cout<<ans<<endl;  // ans
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

