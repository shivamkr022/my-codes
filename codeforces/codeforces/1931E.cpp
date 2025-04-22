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
int getLength(int num1) {
    return to_string(abs(num1)).length();
}
/* write core logic here */
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int tot = 0;
	vector<int> b;
	for(int ele : arr){
		int t = to_string(ele).size();
		int z = 0;
		while(ele % 10 == 0){
			ele /= 10;
			z++;
		}
		t -= z;
		tot += t;
		b.push_back(z); // pushing size of each ele apart from leading zeroes
	}
   // print(b);
	sort(b.rbegin(),b.rend());
	for(int i = 1; i < b.size(); i += 2){
		tot += b[i];
	}
    if(tot>m){
        cout<<"Sasha"<<endl;
    }
    else{
        cout<<"Anna"<<endl;
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

