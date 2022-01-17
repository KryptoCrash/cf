#include <bits/stdc++.h>
using namespace std;

using ll = int;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

void solve() {
    ll n, m;
    cin >> n >> m;

    vi a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vi> s(n, vi(m));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            char c;
            cin >> c;
            s[i][j] = c - '0';
        }
    }

    ll best = -1;
    vi bestp(m);
    for (ll msk = 0; msk < 1 << n; msk++) {
        ll ans = 0;

        for (ll i = 0; i < n; i++) {
            ans += a[i] * (msk & (1 << i) ? -1 : 1);
        }

        vector<vi> coeff(22);
        for (ll j = 0; j < m; j++) {
            ll cnt = 0;
            for (ll i = 0; i < n; i++) {
                cnt += s[i][j] * (msk & (1 << i) ? 1 : -1);
            }
            coeff[cnt + 10].push_back(j);
        }

        vi p(m);
        ll curr = 1;
        for (ll i = 0; i < 22; i++) {
            for(ll j : coeff[i]) {
                ans += (i - 10) * curr;
                p[j] = curr;

                curr++;
            }
        }

        if (ans > best) {
            best = ans;
            bestp = p;
        }
    }

    for (ll i : bestp) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}