// 
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int x, y;
        cin >> x >> y;
        int k = 15;
        int yc = (y + 1) / 2;

        int y1 = 4 * y;
        int ytcc = k * yc;  // total cell
        int rem = ytcc - y1;   // remaining cells

        if (x <= rem) {
            cout << yc << endl;
        } else {
            int rem2 = x - rem;
            if (rem2 % 15 == 0) {
                int ans = yc + (rem2 / 15);
                cout << ans << endl;
            } else {
                cout << (yc + (rem2 / 15) + 1) << endl;  // fixed this line to ensure proper computation
            }
        }
    }
    return 0;
}
