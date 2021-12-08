#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

const ll mod = 1e9 + 7;

ll binpow(ll x, ll n, ll m) {
    assert(n >= 0);

    x %= m;  // note: m * m must be less than 2^63 to avoid ll overflow

    ll res = 1;

    while (n > 0) {
        if (n % 2 == 1)  // if n is odd

            res = res * x % m;

        x = x * x % m;

        n /= 2;  // divide by two
    }

    return res;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    ll orsum = 0;
    for (ll i = 0; i < m; i++) {
        ll x, y, a;
        cin >> x >> y >> a;
        orsum |= a;
    }

    ll ans = 0;
    ll i = 0;
    while (orsum > 0) {
        if (orsum & 1) ans += binpow(2, n - 1 + i, mod);
        ans %= mod;
        orsum >>= 1;
        i++;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}