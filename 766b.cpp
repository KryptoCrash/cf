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

    vi dist(n * m);
    ll idx = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            ll mx = 0;
            mx = max(mx, abs(i - 0) + abs(j - 0));
            mx = max(mx, abs(i - (n-1)) + abs(j - (m-1)));
            mx = max(mx, abs(i - 0) + abs(j - (m-1)));
            mx = max(mx, abs(i - (n-1)) + abs(j - 0));
            dist[idx++] = mx;
        }
    }

    sort(dist.begin(), dist.end());
    for(ll i : dist) cout << i << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}