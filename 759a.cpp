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

    vi a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 1;
    bool died = false;

    if (a[0]) ans++;

    for (ll i = 1; i < n; i++) {
        if (!a[i] && !a[i - 1]) died = true;
        else if (a[i] && a[i - 1]) ans += 5;
        else if (a[i] && !a[i - 1]) ans += 1;

    }

    if(died) {
        cout << -1 << endl;
        return;
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