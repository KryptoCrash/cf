#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 998244353;

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

int main() {
    ll n;
    cin >> n;

    ll dp[2];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (ll i = 0; i < n; i++) {
        dp[i % 2] += dp[1 - (i % 2)];
        dp[i % 2] %= mod;
    }

    ll num = dp[1 - (n % 2)] % mod;
    ll ans = (num * modinv(binpow(2, n))) % mod;
    cout << ans << endl;

    return 0;
}