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
    int f = arr[0];
    int cf = 0;
    int l = arr[n-1];
    int cl = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==f){
            cf++;
        }
        else{
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(arr[i]==l){
            cl++;
        }
        else{
            break;
        }
    }
    int lol=0;
    int i=0;
    int j=n-1;
    while(i<j){
        if(arr[i]==f and arr[j]==f){
            lol+=2;
            i++;
            j--;
        }
        else if(arr[i]!=f and arr[j]==f){
            lol++;
            j--;
        }
        else if(arr[i]==f and arr[j]!=f){
            lol++;
            i++;
        }
        else{
            break;
        }
    }
  //  debug(cf);
   // debug(cl);
    int mm = mx(cf,cl,lol);
   // debug(lol);
   // debug(mm);
    cout<<(n-mm)<<endl;
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

