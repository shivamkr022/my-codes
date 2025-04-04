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

vector<int> getPre(const vector<int>& arr, int sz) {
    vector<int> pre(sz + 1, 0);
    for (int i = 1; i <= sz; i++) {
        pre[i] = pre[i - 1] + arr[i - 1];
    }
    return pre;
}
vector<int> getLarr(const vector<int>& pre, int sz, int tgt) {
    vector<int> Larr(sz, 0);
    int sumT = pre[sz];
    for (int i = 0; i < sz; i++) {
        int rem = sumT - pre[i];
        if (rem >= tgt) {
            int lo = i + 1, hi = sz, best = sz;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (pre[mid] - pre[i] >= tgt) {
                    best = mid;
                    hi = mid - 1;
                }
                else {
                    lo = mid + 1;
                }
            }
            Larr[i] = best - i;
        } else {
            int need = tgt - rem;
            int cyc = (need + sumT - 1) / sumT;
            int base = (sz - i) + (cyc - 1) * sz;
            int req = tgt - ((sumT - pre[i]) + (cyc - 1) * sumT);
            int idx = lower_bound(pre.begin(), pre.end(), req) - pre.begin();
            Larr[i] = base + idx;
        }
    }
    return Larr;
}
int getAns(int sz, int rep, int tgt, const vector<int>& arr) {
    vector<int> pre = getPre(arr, sz);
    vector<int> Larr = getLarr(pre, sz, tgt);
    int res = 0;

    for (int i = 0; i < sz; i++) {
        int L = Larr[i];
        int maxV = rep * sz - i - L;
        if (maxV < 0) continue;
        int maxJ = maxV / sz;
        if (maxJ >= rep) maxJ = rep - 1;
        res += (maxJ + 1);
    }
    return res;
}
/* write core logic here */
void solve(){
    int sz, rep, tgt;
    cin >> sz >> rep >> tgt;

    vector<int> arr(sz);
    for (int i = 0; i < sz; i++) {
        cin >> arr[i];
    }
    cout << getAns(sz, rep, tgt, arr) <<endl;   
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

