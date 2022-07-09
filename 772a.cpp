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

    vb use(31);

    for (ll i = 0; i < n; i++) {
        for (ll b = 0; b <= 30; b++) {
            if (a[i] & (1 << b)) use[b] = true;
        }
    }

    ll ans = 0;
    for (ll b = 0; b <= 30; b++) {
        if(use[b]) ans += (1 << b);
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