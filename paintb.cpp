#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll m;
    cin >> m;

    vi a(m);
    for(ll i = 0; i < m; i++) {
        cin >> a[i];
    }

    auto it = unique(a.begin(), a.end());
    ll n = distance(a.begin(), it);
    a.resize(n);

    set<ll> ac;

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        if (i < 2) ac.insert(a[i]);
    }

    if(ac.size() < 2) {
        cout << 1 << endl;
        return 0;
    }

    ans = 2;

    for (ll i = 2; i < n; i++) {
        if(ac.find(a[i]) != ac.end()) {
            ac.clear();
            ac.insert(a[i - 1]);
        } else
            ans++;
        ac.insert(a[i]);
    }

    cout << ans << endl;

    return 0;
}