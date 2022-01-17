#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

const int ma = 20000002;
ll cnt[ma + 8];
long long dp[ma + 8];
ll primes[ma + 8];
ll vis[ma + 8];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vi a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (ll i = 0; i < n; i++) {
        cnt[a[i]]++;
    }

    ll lst = 0;
    // find p-fact of the numbers ans use it to upd primes freq
    for (long long i = 2; i <= ma; i++) {
        if (vis[i] || i * i > ma) continue;
        primes[lst++] = i;
        for (ll j = i * i; j <= ma; j += i) {
            vis[j] = true;
        }
    }

    for (int i = 1; i <= ma; ++i)
        for (int j = 2 * i; j <= ma; j += i)
            cnt[i] += cnt[j];

    long long best = 0;
    for (ll x = 1; x <= ma; x++)
        for (ll v = 0; (v < lst) && (x * primes[v] <= ma); v++)
            dp[primes[v] * x] = max(dp[primes[v] * x], dp[x] + (long long)x * (cnt[x] - cnt[primes[v] * x]));

    for (ll x = 1; x <= ma; x++)
        best = max(best, dp[x] + x * cnt[x]);

    cout << best << endl;

    return 0;
}