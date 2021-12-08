#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

const ll mod = 1e9+7;
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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vi a(n);
    ll esum = 0;

    vi cnt(n);

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) esum++;
        while (a[i] % 2 == 0) a[i] /= 2, cnt[i]++;
    }

    vi r(31);
    for (ll i = 0; i < n; i++) {
        r[cnt[i]]++;
    }

    ll ans = 0;

    ans += binpow(2, n, mod);
    ans %= mod;
    ans -= binpow(2, esum, mod);
    ans %= mod;
    ll sum = 1;

    for (ll i = 30; i >= 1; i--) {
        if(r[i] > 1) {
            ans += (sum * (binpow(2, r[i] - 1, mod) - 1));
        }
        ans %= mod;

        sum *= binpow(2, r[i], mod);
        sum %= mod;
    }

    ans %= mod;

    cout << ans << endl;

    return 0;
}