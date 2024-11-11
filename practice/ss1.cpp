// #include <iostream>
// #include <string>
// using namespace std;

// // Function to check if Alice will meet the Red Queen
// bool willMeetRedQueen(int n, int a, int b, const string& s) {
//     // Initial position of Alice
//     int x = 0, y = 0;

//     // Calculate the net displacement after one cycle of moves
//     int dx = 0, dy = 0;
//     for (char move : s) {
//         if (move == 'N') dy++;
//         else if (move == 'E') dx++;
//         else if (move == 'S') dy--;
//         else if (move == 'W') dx--;
//     }

//     // Check if Alice reaches (a, b) in the first cycle
//     x = 0, y = 0;
//     for (char move : s) {
//         if (x == a && y == b) return true;
//         if (move == 'N') y++;
//         else if (move == 'E') x++;
//         else if (move == 'S') y--;
//         else if (move == 'W') x--;
//     }
//     if (x == a && y == b) return true; // Check at the end of the first cycle

//     // If net displacement is zero, Alice will never move away from (0, 0)
//     if (dx == 0 && dy == 0) return false;

//     // Check if Alice can reach (a, b) after repeating cycles
//     int remaining_x = a - x;
//     int remaining_y = b - y;

//     // Check if the remaining distance can be covered by multiples of (dx, dy)
//     if (dx != 0 && remaining_x % dx == 0 && remaining_x / dx >= 0 &&
//         dy != 0 && remaining_y % dy == 0 && remaining_y / dy >= 0 &&
//         remaining_x / dx == remaining_y / dy) {
//         return true;
//     }

//     return false;
// }

// int main() {
//     int t;
//     cin >> t;

//     while (t--) {
//         int n, a, b;
//         string s;
//         cin >> n >> a >> b >> s;

//         if (willMeetRedQueen(n, a, b, s)) {
//             cout << "YES\n";
//         } else {
//             cout << "NO\n";
//         }
//     }

//     return 0;
// }




//22222

#include <iostream>
#include <string>
using namespace std;

// Function to determine if Alice can eventually reach the Red Queen
bool canAliceMeetRedQueen(int n, int a, int b, const string& s) {
    // Alice's initial position
    int x = 0, y = 0;

    // Compute the net effect of one complete traversal of the string s
    int totalDx = 0, totalDy = 0;
    for (char move : s) {
        if (move == 'N') totalDy++;
        else if (move == 'E') totalDx++;
        else if (move == 'S') totalDy--;
        else if (move == 'W') totalDx--;
    }

    // Check if Alice meets the Red Queen during the first traversal
    for (char move : s) {
        if (x == a && y == b) return true; // Alice has reached the target
        if (move == 'N') y++;
        else if (move == 'E') x++;
        else if (move == 'S') y--;
        else if (move == 'W') x--;
    }

    // If Alice ends at (a, b) after the first full cycle
    if (x == a && y == b) return true;

    // If the net movement is zero, Alice repeats the same path forever
    if (totalDx == 0 && totalDy == 0) return false;

    // Check if there is a way for Alice to reach (a, b) in repeated cycles
    int remainingX = a - x;
    int remainingY = b - y;

    // To match the position (a, b), the remaining distance should be covered
    // as a multiple of (totalDx, totalDy) steps, and both must be non-negative
    if (totalDx != 0 && remainingX % totalDx == 0 && remainingX / totalDx >= 0 &&
        totalDy != 0 && remainingY % totalDy == 0 && remainingY / totalDy >= 0 &&
        remainingX / totalDx == remainingY / totalDy) {
        return true;
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, a, b;
        string s;
        cin >> n >> a >> b >> s;

        // Output "YES" if Alice can meet the Red Queen, otherwise "NO"
        cout << (canAliceMeetRedQueen(n, a, b, s) ? "YES" : "NO") << endl;
    }

    return 0;
}
