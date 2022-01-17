#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

const ll maxn = 5008;
ll C[maxn + 1][maxn + 1];

const ll mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    C[0][0] = 1;
    for (ll n = 1; n <= maxn; ++n) {
        C[n][0] = C[n][n] = 1;
        for (ll k = 1; k < n; ++k) {
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
            C[n][k] %= mod;
        }
    }

    ll n, k;
    cin >> n >> k;
    vb s(n);

    ll tot_k = 0;
    for (ll i = 0; i < n; i++) {
        char c;
        cin >> c;
        s[i] = c - '0';
        tot_k += s[i];
    }

    vi psum(n + 1);

    for (ll i = 1; i <= n; i++) {
        psum[i] = psum[i - 1] + s[i - 1];
    }

    ll ans = 1;

    if (tot_k < k) {
        cout << ans << endl;
        return 0;
    }

    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            ll num_k = psum[j + 1] - psum[i];
            if (num_k > k) continue;
            num_k -= 2 - (s[i] + s[j]);

            ll sz = j - i - 1;

            if (sz < 0 || num_k < 0 || sz < num_k) continue;
            ans += C[sz][num_k];
            ans %= mod;
        }
    }

    cout << ans << endl;

    return 0;
}