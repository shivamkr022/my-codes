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

int get_value(int x, int y, int len, int base) {
    if (len == 2) {
        if (x % 2 == 1 && y % 2 == 1) return base;
        if (x % 2 == 0 && y % 2 == 0) return base + 1;
        if (x % 2 == 0 && y % 2 == 1) return base + 2;
        return base + 3;
    }
    int half = len / 2;
    int block = 1LL * half * half;

    if (x <= half && y <= half)
        return get_value(x, y, half, base);
    else if (x > half && y > half)
        return get_value(x - half, y - half, half, base + block);
    else if (x > half && y <= half)
        return get_value(x - half, y, half, base + 2 * block);
    else
        return get_value(x, y - half, half, base + 3 * block);
}
pair<int, int> get_pos(int d, int len, int base, int off_x, int off_y) {
    if (len == 2) {
        if (base == d) return {off_x + 1, off_y + 1};
        if (base + 1 == d) return {off_x + 2, off_y + 2};
        if (base + 2 == d) return {off_x + 2, off_y + 1};
        return {off_x + 1, off_y + 2};
    }
    int half = len / 2;
    int block = 1LL * half * half;
    if (d < base + block) return get_pos(d, half, base, off_x, off_y);
    else if (d < base + 2 * block) return get_pos(d, half, base + block, off_x + half, off_y + half);
    else if (d < base + 3 * block) return get_pos(d, half, base + 2 * block, off_x + half, off_y);
    else return get_pos(d, half, base + 3 * block, off_x, off_y + half);
}
/* write core logic here */
void solve(){
    int n, q;
    cin >> n >> q;
    int len = 1 << n; 
    while (q--) {
        string str;
        cin >> str;
        if (str == "->") {
            int x, y;
            cin >> x >> y;
            cout << get_value(x, y, len, 1) << endl;
        }
        else {
            int d;
            cin >> d;
            pair<int, int> res = get_pos(d, len, 1, 0, 0);
            cout << res.first << " " << res.second << endl;
        } 
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
   // t = 1;
    while(t--){
        solve();
    }
return 0;
}

