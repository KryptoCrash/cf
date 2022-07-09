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

    if(is_sorted(a.begin(), a.end())) {
        cout << 0 << endl;
        return;
    }

    if(a[n - 2] > a[n - 1] || (a[n - 1] < 0)) {
        cout << -1 << endl;
        return;
    }

    cout << n - 2 << endl;

    for (ll i = n - 3; i >= 0; i--) {
        cout << i+1 << " " << n - 1 << " " << n << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}