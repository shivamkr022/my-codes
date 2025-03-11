#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> b(2 * n);
        for (int i = 0; i < 2 * n; ++i) {
            cin >> b[i];
        }

        // Sort b to make it easier to handle
        sort(b.begin(), b.end());

        // Try to find the missing element
        long long missing = -1;
        for (int i = 0; i <= 2 * n; ++i) {
            // Construct a candidate for a
            vector<long long> a;
            int idx = 0;
            for (int j = 0; j <= 2 * n; ++j) {
                if (j == i) {
                    a.push_back(0); // Placeholder for missing element
                } else {
                    a.push_back(b[idx++]);
                }
            }

            // Calculate the alternating sum
            long long sum = a[1];
            for (int j = 2; j < 2 * n + 1; ++j) {
                if (j % 2 == 0) {
                    sum -= a[j];
                } else {
                    sum += a[j];
                }
            }

            // Check if the sum matches a[0]
            if (sum == a[0]) {
                missing = a[i];
                break;
            }
        }

        // Reconstruct a with the missing element
        vector<long long> a;
        a.push_back(missing);
        for (int i = 0; i < 2 * n; ++i) {
            a.push_back(b[i]);
        }

        // Output the sequence a
        for (int i = 0; i < 2 * n + 1; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
}