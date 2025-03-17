#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x;
        cin >> x;
        bool found = false;

        // Try every y in the range [1, x-1]
        for (int y = 1; y < x; y++) {
            int z = x ^ y;  // x ⊕ y

            // Check the triangle inequalities
            if (x + y > z && x + z > y && y + z > x) {
                cout << y << endl;
                found = true;
                break;  // We found a valid y, no need to check further
            }
        }

        if (!found) {
            cout << -1 << endl;  // No valid y found
        }
    }

    return 0;
}
