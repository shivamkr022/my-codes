#include <bits/stdc++.h>
 
using namespace std;
 
int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        k = min(k, 30);
        int tt= pow(2,k);
        cout<< min(n+1,tt)<<endl;
    }
    return 0;
}