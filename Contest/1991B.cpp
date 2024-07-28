#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            cin >> b[i];
        }

        // To satisfy b[i] = a[i] & a[i+1], we can just set a[i+1] = b[i]
        vector<int> a(n);
        a[0] = b[0]; // initialize the first element
        for (int i = 1; i < n; ++i) {
            a[i] = b[i - 1];
        }

        // Ensure a[i] & a[i+1] == b[i] for each i
        bool valid = true;
        for (int i = 0; i < n - 1; ++i) {
            if ((a[i] & a[i + 1]) != b[i]) {
                valid = false;
                break;
            }
        }

        if (valid) {
            for (int i = 0; i < n; ++i) {
                cout << a[i] << " ";
            }
            cout << "\n";
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}
