#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> b;
        int expected = 1;
        for (int i = 0; i < n; ++i) {
            if (a[i] == expected) {
                b.push_back(a[i]);
                expected++;
            }
        }
        b.push_back(0);
        int cost = 1;
        for (int i = 0; i < b.size(); ++i) {
            if (b[i] != i + 1) {
                cost = i + 1;
                break;
            }
        }

        cout << cost << '\n';
    }

    return 0;
}