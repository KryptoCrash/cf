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

    ll x, y;
    cin >> x >> y;

    ll s = x + y;
    ll mx = min(n, s - 1);
    // find first i st i + n = s + 1
    // s + 1 - n = i
    ll mn = n - min(n-1, 2*n-s-1);
    cout << mn << " " << mx << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}