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
    cin>>n;  //crux of tis que is to put the smallest ele 

    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i]; // input
    int x = 1e18;

    for(int i=0;i<n;i++){ 
        x=min(x,arr[i]);  // // Find the minimum element

    }

    vector<int>b;  // to store ele
    vector<int>c;

    for(int i=0;i<n;i++){
        if(arr[i]==x){
            b.push_back(arr[i]);     // just observation
        }
        else {
            c.push_back(arr[i]);    // just observation
        }
    }
    if(b.size()==n) cout<<-1<<endl;  // if same ele in arr

    else{
    cout<<b.size()<<" "<<c.size()<<endl;

    for(int i=0;i<b.size();i++){
        cout<<b[i]<<" ";                  // ans
    }cout<<endl;

    for(int i=0;i<c.size();i++){
        cout<<c[i]<<" ";
    }
  }
  return ;
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

