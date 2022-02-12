#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<array<ll, 3>> s(2*m);
    vi org(m);
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        s[i] = {-a, 0, i};
        s[m + i] = {-b, 1, i};
        org[i] = -a;
    }

    sort(s.begin(), s.end());

    ll mx = 0;
    ll cur = 0;
    vb vis(m);
    for (ll i = 0; i < 2 * m; i++) {
        ll v = -s[i][0];
        ll idx = s[i][2];
        ll tp = s[i][1];

        if (n == 0) break;

        if(tp == 0) {
            cur += v;
            mx = max(mx, cur);
            vis[idx] = true;

            n--;
        } else {
            ll val = 0;
            val = v * (n - 1);
            if (vis[idx]) val += v;
            else
                val += -org[idx];
            mx = max(mx, cur + val);
        }
    }

    cout << mx << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}