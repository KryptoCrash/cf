// C++ program for the above approach

#include "bits/stdc++.h"
using namespace std;

// Function for finding all divisors
// of a given number
vector<int> getDivisors(int diff) {
    // Stores the divisors of the
    // number diff
    vector<int> divisor;

    for (int i = 1; i * i <= diff; i++) {
        // If diff is a perfect square
        if (i == diff / i) {
            divisor.push_back(i);
            continue;
        }

        // If i divides diff then
        // diff / i also a divisor
        if (diff % i == 0) {
            divisor.push_back(i);
            divisor.push_back(diff / i);
        }
    }

    // Return the divisors stored
    return divisor;
}

// Function to find smallest integer x
// such that LCM of (A + X) and (B + X)
// is minimized
int findTheSmallestX(int a, int b) {
    int diff = b - a;

    // Find all the divisors of diff
    vector<int> divisor = getDivisors(diff);

    // Find LCM of a and b
    int lcm = (a * b) / __gcd(a, b);

    int ans = 0;

    for (int i = 0;
         i < (int)divisor.size(); i++) {
        // From equation x = M - a % M
        // here M = divisor[i]
        int x = (divisor[i] - (a % divisor[i]));

        // If already checked for x == 0
        if (!x)
            continue;

        // Find the product
        int product = (b + x) * (a + x);

        // Find the GCD
        int tempGCD = __gcd(a + x, b + x);
        int tempLCM = product / tempGCD;

        // If current lcm is minimum
        // than previous lcm, update ans
        if (lcm > tempLCM) {
            ans = x;
            lcm = tempLCM;
        }
    }

    // Print the number added
    cout << ans << endl;
}

// Driver Code
int main() {
    // Given A & B
    int A, B;
    cin >> A >> B;

    // Function Call
    findTheSmallestX(A, B);

    return 0;
}
