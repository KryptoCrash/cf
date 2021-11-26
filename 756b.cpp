#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

void solve() {
    ll a, b;
    cin >> a >> b;

    if (b > a) swap(a, b);

    ll d = a - b;
    ll tteams = min(b, d / 2);
    ll ans = tteams;
    a -= tteams * 3;
    b -= tteams;
    ll d2 = min(a, b);
    ans += d2 / 2;

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