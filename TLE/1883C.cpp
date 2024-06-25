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
    vector<int>arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];
int x1=1;
int x2=2;
	int d = k-1;
	int e_cnt = 0;
	for(int i=0; i<n; i++){
		if(arr[i]%2==0)e_cnt++;
 
		if(arr[i]%k == 0)
			d = 0;
		else
			d = min(d, k-arr[i]%k);
	}
 
	if(k!=4){
		cout<<d<<endl;
	}else{
		if(e_cnt >= 2)
			cout<<0<<endl;
		else if(e_cnt == 1)
			cout<<min(d, x1)<<endl;
		else//13 17
			cout<<min(x2, d)<<endl;
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

