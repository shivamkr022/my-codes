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
    int n,k;
    cin>>n>>k;

    if(k%2==1){
        cout<<"NO"<<endl;
        return;
    }
    vector<int>arr;
    for(int i=0;i<n;i++){
        arr.push_back(i+1);
    }
    k/=2;
    int x = n-1;
    for(int i=0;i<n;i++){
        if(k<=x){
            swap(arr[i],arr[i+k]);
            k=0;
            break;
        }
        else{
            swap(arr[i],arr[i+x]);
            k-=x;
            x-=2;
            if(k<=0) break;
        }
    }

    if(k>0){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
    }cout<<endl;
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

