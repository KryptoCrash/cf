#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;

    ll k = abs(2 * b - (a + c)) / 3;
    ll best = 1e9;
    for (ll i = k - 3; i < k + 3; i++) {
        if ((a + c) > 2 * b) {
            best = min(best, abs((a + c - i) - 2 * (b + i)));
        } else {
            best = min(best, abs(2 * (b - i) - (a + c + i)));
        }
    }

    cout << best << endl;
}

int main() {
    ll t;
    cin >> t;

    while (t--) solve();

    return 0;
}