#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        if (n < 3) {
            for (int i = 0; i < n; i++) {
                long long temp;
                cin >> temp;
            }
            cout << 0 << '\n';
            continue;
        }

        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());

        long long globalMax = a[n - 1], ans = 0;

        for (int k = 2; k < n; k++) {
            long long z = a[k];
            long long threshold = max(z, globalMax - z);

            int l = 0, r = k - 1;
            while (l < r) {
                if (a[l] + a[r] > threshold) {
                    ans += (r - l);
                    r--;
                } else {
                    l++;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
