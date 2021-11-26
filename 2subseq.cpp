#include <bits/stdc++.h>
using namespace std;

using ll = double;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

const int inf = 1e9;

void solve() {
    ll n;
    cin >> n;

    vi a(n);
    ll mx = -inf;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        sum += a[i];
    }

    cout.precision(17);

    cout << (mx + ((sum - mx) / (n - 1))) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}