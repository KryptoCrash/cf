#include <bits/stdc++.h>

using namespace std;

int solve() {
    int n, k;
    cin >> n >> k;
    k--;

    if (n % 2 == 0) return k % n + 1;
    else {
        int offset = k / ((n - 1) / 2);
        return (k + offset) % n + 1;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) cout << solve() << endl;
}