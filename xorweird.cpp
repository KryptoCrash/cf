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
    ll n, k;
    cin >> n >> k;

    ll ans = 0;

    for (ll i = 0; i < k; i++) {
        // i and k - i - 1
        ll j = k - i - 1;

        // ans = (2^ni) * (2^(nj-j)) * (2^(n-1) - 1)
        ll prod = 1;

        if(j != 0) {
            prod *= binpow((binpow(2, n - 1, mod) - (n % 2 == 0 ? 1 : 0) + (n % 2 == 1 ? 1 : 0)) % mod, j, mod) % mod;
            prod %= mod;
        }

        prod *= (n % 2 == 0 ? 1 : 0);
        prod %= mod;

        prod *= binpow(2, n * i, mod);
        prod %= mod;

        ans += prod;
        ans %= mod;
    }

    ans += binpow((binpow(2, n - 1, mod) - (n % 2 == 0 ? 1 : 0) + (n % 2 == 1 ? 1 : 0)) % mod, k, mod) % mod;
    ans %= mod;

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