#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll maxn = 1e5 + 8;


int main(int argc, char const *argv[]) {
    ll n, q, k;

    cin >> n >> q >> k;

    ll a[maxn];
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // Edge cases on edge of array
    a[0] = 0;
    a[n + 1] = k + 1;

    ll psum[maxn];
    ll ssum[maxn];

    for (ll i = 1; i <= n; i++) {
        psum[i] = a[i + 1] - a[i] - 1;
        ssum[i] = a[i] - a[i - 1] - 1;
    }

    ll tsum[maxn];
    tsum[0] = 0;

    for (ll i = 1; i <= n; i++) {
        tsum[i] = tsum[i - 1] + psum[i] + ssum[i];
    }

    for (ll i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;

        ll tot = tsum[r] - tsum[l - 1];

        tot -= ssum[l];
        tot -= psum[r];

        tot += a[l] - 1;
        tot += k - a[r];

        cout << tot << endl;
    }

    return 0;
}