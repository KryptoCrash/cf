#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    vi a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    vi b(m);
    for(ll i = 0; i < m; i++) {
        cin >> b[i];
    }

    vpi p(k);
    for (ll i = 0; i < k; i++) {
        cin >> p[i].first >> p[i].second;
    }

    ll ans = 0;
    vi sc(n);
    vi sr(m);
    map<pi, ll> ma;
    map<pi, ll> mb;
    for (ll i = 0; i < k; i++) {
        ll sgv = lower_bound(a.begin(), a.end(), p[i].first) - a.begin();
        ll sgh = lower_bound(b.begin(), b.end(), p[i].second) - b.begin();
        if (p[i].first != a[sgv]) ans += sc[sgv] - ma[{sgv, sgh}], ma[{sgv, sgh}]++, sc[sgv]++;
        if (p[i].second != b[sgh]) ans += sr[sgh] - mb[{sgv, sgh}], mb[{sgv, sgh}]++, sr[sgh]++;
    }

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