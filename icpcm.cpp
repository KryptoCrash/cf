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

    ll m;
    cin >> m;

    ll x = 0;
    ll y = 0;

    for (int j = 0; j < m; j++) {
        ll q, r;
        cin >> q >> r;
        x = max(x, q);
        y = max(y, r);
    }
    if (x + y > n)
        cout << "IMPOSSIBLE" << endl;
    else {
        string s;
        for (int i = 0; i < x; i++) {
            s += 'R';
        }

        for (int i = 0; i < y; i++) {
            s += 'W';
        }

        for (int i = 0; i < n - (x + y); i++) {
            s += 'W';
        }
        cout << s << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}