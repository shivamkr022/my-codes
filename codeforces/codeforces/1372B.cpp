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
bool isPrime(int num) {
    if (num <= 1) return false;         // 0 and 1 are not prime
    if (num == 2) return true;          // 2 is the only even prime
    if (num % 2 == 0) return false;     // even numbers >2 are not prime
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}
/* write core logic here */
void solve(){
    int n;
    cin>>n;
    if(n%2==0){
        cout<<(n/2)<<" "<<(n/2)<<endl;
        return;
    }
    if(isPrime(n)){
        cout<<1<<" "<<(n-1)<<endl;
        return;
    }
    int a =0;
    int b =0;
    for(int i=3;i*i<=n;i++){
        if(n%i==0){
            int d = n/i;
            int rem = n-d;
            if(rem+d==n){
                a=d;
                b=rem;
                break;
            }
        }
    }
    cout<<a<<" "<<b<<endl;
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

