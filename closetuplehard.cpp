#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll maxn = 2e5+5;
const ll mod = 1e9 + 7;

ll fact[maxn+10]{0};
ll invfact[maxn+10]{0};

ll binpow(ll x, ll n) {
    assert(n >= 0);
    x %= mod;  //note: m*m must be less than 2^63 to avoid ll overflow
    ll res = 1;
    while (n > 0) {
        if (n % 2 == 1)  //if n is odd
            res = res * x % mod;
        x = x * x % mod;
        n /= 2;  //divide by two
    }
    return res;
}

ll modinv(ll x) {
    return binpow(x, mod - 2);
}

void precompute() {
    fact[0] = 1;
    invfact[0] = 1;

    for (ll i = 1; i < maxn; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        invfact[i] = modinv(fact[i]);
    }
}

ll choose(ll n, ll k) {
    if (n < k) return 0;
    return (fact[n] * ((invfact[k] * invfact[n - k] % mod))) % mod;
}

bool ok(ll mn, ll mx, ll k) { return mx - mn <= k; }

ll solve() {
    ll sum = 0;

    ll n, m, k;
    cin >> n >> m >> k;

    ll a[maxn];
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    ll lo = 0;
    for (ll mn = 0; mn < n; mn++) {
        ll hi = n - 1;

        // bin search for max
        while (lo < hi) {
            ll mx = (hi + lo + 1) / 2;
            if (ok(a[mn], a[mx], k)) {
                lo = mx;
            } else {
                hi = mx - 1;
            }
        }

        // Calculate possible tuples in range (mn, mx)
        ll p = lo - mn;
        ll c = m - 1;
        sum += choose(p, c);
        sum %= mod;
    }

    return sum;
}

int main() {
    ll t;
    cin >> t;

    precompute();

    while (t--) {
        cout << solve() << endl;
    }

    return 0;
}
