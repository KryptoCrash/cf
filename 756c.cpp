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

    ll mx = 0;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    if(a[0] == mx || a[n - 1] == mx) {
        reverse(a.begin(), a.end());

        for(ll i : a) {
            cout << i << " ";
        }
        cout << endl;
    } else
        cout << -1 << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}