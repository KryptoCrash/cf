#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

const ll mod = 998244353;

void solve() {
    ll n;
    cin >> n;

    vi a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    vpi f;
    ll ans = 0;
    ll num_break = 0;
    for (ll i = n - 1; i >= 0; i--) {
        vpi f2;
        ll bk = 0;

        for (pi it : f) {
            ll v = it.first;
            ll cnt = it.second;

            ll x = ceil((double)a[i] / v);
            ll first = floor((double)a[i] / x);

            if (first != bk) f2.push_back({first, 0});
            bk = first;
            f2.back().second += cnt;

            num_break += (cnt % mod) * (x - 1);
            num_break %= mod;
        }

        reverse(f2.begin(), f2.end());
        ll first = a[i];

        if (f2.size() == 0 || first != f2.back().first) f2.push_back({first, 0});
        f2.back().second++;

        ans += num_break;
        ans %= mod;

        f = f2;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}