#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

void solve() {
    ll n;
    cin >> n;

    vpi d;

    vi k(n);
    for(ll i = 0; i < n; i++) {
        cin >> k[i];
        d.push_back({k[i], 1});
    }

    vi h(n);
    for(ll i = 0; i < n; i++) {
        cin >> h[i];
    }

    
    for (ll i = 0; i < n; i++) {
        d.push_back({k[i] - h[i] + 1, -1});
    }

    sort(d.begin(), d.end());

    ll ans = 0;
    ll depth = 0;
    ll st = 1;
    for (ll i = 0; i <= d.size(); i++) {
        if(depth == 0) {
            ll sz = (i > 0 ? d[i - 1].first : 0) - st + 1;
            ans += (sz * (sz + 1)) / 2;
            if(i != d.size()) st = d[i].first;
        }

        if (i != d.size()) depth += d[i].second;
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