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
    n = n - 2;

    vi a(n);

    ll ch;
    cin >> ch;
    bool all1 = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != 1) all1 = false;
    }
    cin >> ch;

    if(all1 || (n == 1 && (a[0] % 2))) {
        cout << -1 << endl;
        return;
    }

    ll cnt = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2) cnt++;
        sum += a[i];
    }
    ll ans = cnt + (sum - cnt) / 2;

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