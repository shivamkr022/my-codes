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
    for(int i=0;i<n;i++) cin>>arr[i];
    int xx = *min_element(arr.begin(),arr.end());
    if(xx!=0){
        cout<<1<<endl;
        cout<<1<<" "<<n<<" "<<endl;
        return;
    }
    if(arr[0]!=0 and arr[n-1]!=0){
        cout<<2<<endl;
        cout<<1<<" "<<n-1<<endl;
        cout<<1<<" "<<2<<endl;
    }
    else if(arr[0]==0 and arr[n-1]==0){
        cout<<3<<endl;
        cout<<1<<" "<<n-2<<endl;
        cout<<2<<" "<<3<<endl;//         cout<<n-1<<" "<<n<<endl;
        cout<<1<<" "<<2<<endl;
    }
    else if(arr[0]!=0 ){//and arr[n-1]==0
        cout<<2<<endl;
        cout<<2<<" "<<n<<endl;
        cout<<1<<" "<<2<<endl;
    }
    else if(arr[n-1]!=0 ){//and arr[0]==0
        cout<<2<<endl;
        cout<<1<<" "<<n-1<<endl;
        cout<<1<<" "<<2<<endl;
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

