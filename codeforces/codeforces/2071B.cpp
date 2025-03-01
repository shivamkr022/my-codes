/*
**  Compete against Yourself.
**  Author - Shivam kumar
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
int po(int a,int b) {if(b==0) return 1; if(b==1) return a; if(b%2==0) {int u=po(a,b/2);return (u*1LL*u)%mod;} else {int u=po(a,b-1);return (a*1LL*u)%mod;}}
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define all(x) (x).begin(),(x).end()
using namespace std;
bool isPerfectSquare(int num) {
    if (num < 0) return false;
    int root = static_cast<int>(sqrt(num));
    return root * root == num;
}
vector<int> generatePermutation(int n) {
    vector<int> permutation;
    int currentSum = 0;

    for (int i = 1; i <= n; ++i) {
        if (!isPerfectSquare(currentSum + i)) {
            permutation.push_back(i);
            currentSum += i;
        }
        else {
            if (i < n) {
                permutation.push_back(i + 1);
                permutation.push_back(i);
                currentSum += (i + i + 1);
                ++i;
            }
            else {
                return {};
            }
        }
    }
    return permutation;
}
/* write core logic here */
void solve(){
    int n;
    cin>>n;
    vector<int> result = generatePermutation(n);

    if(result.empty()) {
        cout <<-1<< endl;
    }
    else {
        for(int num : result) {
            cout << num << " ";
        }
        cout << endl;
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