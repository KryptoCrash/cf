#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

void solve() {
    ll n, s;
    cin >> n >> s;

    vi a(n + 1);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll l, r, sum, best, bl, br;
    l = r = sum = best = bl = br = 0;

    while(r < n) {
        sum += a[r++];
        while (sum + s < 0) sum -= a[l++];
        if (r - l > best) best = r - l, br = r, bl = l + 1;
    }

    if (best == 0) cout << -1 << endl;
    else cout << bl << ' ' << br << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}