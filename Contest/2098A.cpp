#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector<int> cnt(10, 0);
        
        for (char c : s) {
            cnt[c - '0']++;
        }
        string ans = "";
        for (int i = 1; i <= 10; ++i) {
            int xx = 10 - i;
            for (int d = xx; d <= 9; d++) {
                if (cnt[d] > 0) {
                    ans += (char)(d + '0');
                    cnt[d]--;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
