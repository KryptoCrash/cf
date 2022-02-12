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

    ll ans = 0;

    for (ll i = 0; i < n; i++) {
        for (ll j = i; j < n; j++) {
            ll cnt = 0;
            for (ll k = i; k <= j; k++) {
                if (a[k] == 0) cnt += 2;
                else cnt++;
            }

            ans += cnt;
        }
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