#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

ll n, m;

bool ok(ll r, vi a, vi b) {
    vector<bool> fixed(n);
    for (ll i = 0; i < m; i++) {
        ll pos = b[i];
        ll lo = lower_bound(a.begin(), a.end(), pos - r) - a.begin();
        ll hi = upper_bound(a.begin(), a.end(), pos + r) - a.begin();

        lo = max((ll)0, min(lo, n));
        hi = max((ll)0, min(hi, n));
        fill(lo + fixed.begin(), hi + fixed.begin(), true);
    }

    for (ll i = 0; i < n; i++) {
        if(!fixed[i]) return false;
    }

    return true;
}

int main() {
    cin >> n >> m;

    vi a(n);
    vi b(m);

    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(ll i = 0; i < m; i++) {
        cin >> b[i];
    }

    ll lo = 0;
    ll hi = 2e9+4;
    
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (ok(mid, a, b)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << hi << endl;

    return 0;
}