#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll maxn = 1e5 + 8;
int main() {
    ll n, m;
    cin >> n >> m;

    bool is_odd[maxn];
    memset(is_odd, 0, sizeof(is_odd));

    for (ll i = 0; i < n; i++) {
        ll num_ones = 0;
        for (ll j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c - '0' == 1) num_ones++;
        }
        is_odd[i] = num_ones % 2 == 1;
    }

    ll psum_evens[maxn];
    ll psum_odds[maxn];

    memset(psum_evens, 0, sizeof(psum_evens));
    memset(psum_odds, 0, sizeof(psum_odds));

    for (ll i = n - 1; i > 0; i--) {
        if (is_odd[i]) {
            psum_odds[i - 1] = psum_odds[i] + 1;
            psum_evens[i - 1] = psum_evens[i];
        } else {
            psum_evens[i - 1] = psum_evens[i] + 1;
            psum_odds[i - 1] = psum_odds[i];
        }
    }

    ll sum = 0;

    for (ll i = 0; i < n - 1; i++) {
        if (is_odd[i])
            sum += psum_evens[i];
        else
            sum += psum_odds[i];
    }

    cout << sum << endl;

    return 0;
}