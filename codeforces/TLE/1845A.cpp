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
    int n,k,x;
    cin>>n>>k>>x;

    if(x!=1){
        cout<<"YES"<<endl;
        cout<<n<<endl;
        for(int i=0;i<n;i++) // if x!=1 
        cout<<1<<" ";
    }

    else if(k==1) cout<<"NO"<<endl; // if k==1 then we cant do anything

    else if(n%2==0){  // n is even and x==1
        if(x==1){
            cout<<"YES"<<endl;
            cout<<n/2<<endl;
            for(int i=0;i<n/2;i++){
                cout<<2<<" ";
            }
        } cout<<endl;
    } 
    else if(n%2!=0){
        if(x==1){
            if(k==2){
                cout<<"NO"<<endl;
            }
            else{
            vector<int>v1;
            v1.push_back(3);
            for(int i=0;i<n/2-1;i++) {
                v1.push_back(2);
            }
            cout<<"YES"<<endl;
            cout<<n/2<<endl;
            for(int i=0;i<v1.size();i++) {
                cout<<v1[i]<<endl;
               }
            }
        } 
    }cout<<endl;
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

