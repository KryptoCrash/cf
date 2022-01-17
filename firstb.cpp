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

    vi b(n);
    vi c(n);

    ll bsum = 0;
    ll csum = 0;

    for (ll i = 0; i < n; i++) {
        if (i % 2) b[i] = a[i], c[i] = 1;
        else
            b[i] = 1, c[i] = a[i];

        bsum += abs(b[i] - a[i]);
        csum += abs(c[i] - a[i]);
    }

    if(csum < bsum) {
        for (ll i : c) cout << i << " ";
    } else {
        for (ll i : b) cout << i << " ";
    }
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