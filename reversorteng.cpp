#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int revsort(vector<ll> a, ll n) {
    ll sum = 0;

    for (ll i = 0; i < n; i++) {
        auto st = a.begin() + i;
        auto best = min_element(st, a.end());

        sum += best - st + 1;
        reverse(st, best + 1);
    }

    return sum - 1;
}

void solve() {
    ll n, c;
    cin >> n >> c;

    ll base = n - 1;
    ll needed = c - base;
    ll max = base * ((1 + base) / 2.0);

    vector<ll> a;
    for (ll i = 1; i <= n; i++) {
        a.push_back(i);
    }

    if (needed <= max && needed >= 0) {
        set<ll> swaps;
        for (ll i = base; i > 0; i--) {
            if (needed - i >= 0) {
                needed -= i;
                swaps.insert(i);
            }
        }
        assert(needed == 0);

        for (ll i : swaps) {
            reverse(a.end() - i - 1, a.end());
        }

        assert(revsort(a, n) == c);

        for (ll i : a) {
            cout << i << " ";
        }

        return;
    }

    cout << "IMPOSSIBLE";
}

int main() {
    ll t;
    cin >> t;

    for (ll i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }

    return 0;
}