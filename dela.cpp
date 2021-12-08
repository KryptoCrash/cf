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

    ll mx = 0;
    ll cnt = 0;
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        ll cur = a[i];
        while (cur % 2 == 0) cur /= 2, cnt++;
        mx = max(mx, cur);
        sum += cur;
    }

    cout.precision(62);
    cout << ((sum - mx) + mx * pow(2, cnt)) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}