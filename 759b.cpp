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
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll rmx = 0;

    ll cnt = 0;
    for (ll i = n - 1; i >= 0; i--) {
        if (a[i] > rmx) cnt++, rmx = a[i];
    }

    cout << cnt - 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}