#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve() {
    ll x, g;
    cin >> x >> g;

    ll tot = 0;
    for (ll y = 1; y <= g; y++) {
        ll range_i = x / y;
        range_i = min(range_i, y - 1);
        ll c_tot = 0;
        c_tot += range_i - 1;
        c_tot += (1 ? x >= (range_i * y + range_i) : 0);

        tot += c_tot;
    }

    return tot;
}

int main(int argc, char const *argv[]) {
    ll t;
    cin >> t;
    while(t--) cout << solve() << endl;

    return 0;
}