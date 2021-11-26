#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

const ll inf = 1e9;

void solve() {
    ll n, c;
    cin >> n >> c;

    vi a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    vi b(n);
    for(ll i = 0; i < n-1; i++) {
        cin >> b[i];
    }

    ll ans = inf;
    ll days = 0;
    ll bal = 0;
    for (ll i = 0; i < n; i++) {
        ll days_taken_comp = (ll)ceil((double)(c - bal) / a[i]) + days;
        ans = min(ans, days_taken_comp);
        if (i == n - 1) break;

        ll days_taken = (ll)ceil((double)(b[i] - bal) / a[i]);
        days += days_taken + 1;
        bal = days_taken * a[i] + bal - b[i];
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