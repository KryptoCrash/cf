#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve() {
    int x, y;
    cin >> x >> y;

    ll sum = 0;
    for (int i = 1; i < sqrt(x); i++) {
        sum += max(0, min(x / i - 1, y) - i);
    }

    return sum;
}

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;

    while (t--) {
        cout << solve() << endl;
    }

    return 0;
}
