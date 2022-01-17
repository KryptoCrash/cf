#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

void solve() {
    ll n, k;
    cin >> n >> k;

    vi a;
    vi b;
    for (ll i = 0; i < n; i++) {
        ll c;
        cin >> c;
        if (c == 0) continue;
        if (c > 0) a.push_back(c);
        if (c < 0) b.push_back(-c);
    }

    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());
    vi trips;

    for (ll i = 0; i < a.size(); i += k) {
        trips.push_back(a[i]);
    }

    for (ll i = 0; i < b.size(); i += k) {
        trips.push_back(b[i]);
    }

    ll ans = 0;
    sort(trips.begin(), trips.end(), greater<ll>());

    for (ll i : trips) {
        ans += i * 2;
    }

    ans -= trips[0];

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}