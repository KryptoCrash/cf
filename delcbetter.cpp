#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

vb prime(1e6 + 8, true);

void solve() {
    ll n, e;
    cin >> n >> e;

    vi a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        if (!prime[a[i]]) continue;
        ll l, r;
        l = r = i;
        ll cnt0, cnt1;
        cnt0 = cnt1 = 0;
        while (l >= 0 && (a[l] == 1 || l == i)) {
            cnt0++;
            l -= e;
        }
        while (r < n && (a[r] == 1 || r == i)) {
            cnt1++;
            r += e;
        }
        ans += cnt0 * cnt1 - 1;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    prime[0] = prime[1] = false;
    for (ll i = 2; i < (1e6 + 8); i++) {
        if (prime[i] && (long long)i * i < (1e6 + 8)) {
            for (ll j = i * i; j < (1e6 + 8); j += i)
                prime[j] = false;
        }
    }

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}