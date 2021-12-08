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

    vi a(n+1);
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll tot = 0;

    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= n; k++) {
            if (i + e * k > n) continue;
            ll prod = 1;
            for (int j = 0; j <= k; j++) {
                prod *= a[i + e * j];
            }

            if (prime[prod]) tot++;
        }
    }

    cout << tot << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    prime[0] = prime[1] = false;
    for (int i = 2; i < (1e6 + 8); i++) {
        if (prime[i] && (long long)i * i < (1e6 + 8)) {
            for (int j = i * i; j < (1e6 + 8); j += i)
                prime[j] = false;
        }
    }

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}