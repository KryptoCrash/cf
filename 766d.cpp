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

    ll n;
    cin >> n;

    vi a(n);
    vi vis(1e6+8);
    ll mx = 0;
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        vis[a[i]] = true;
    }

    for (ll g = 1; g <= mx; g++) {
        ll cur = 0;

        for (ll m = g; m <= mx; m += g) {
            if(vis[m]) {
                cur = __gcd(cur, m);
                if(cur == g) {
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans - n << endl;

    return 0;
}