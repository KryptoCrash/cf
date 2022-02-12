#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

void solve() {
    ll l, r, k;
    cin >> l >> r >> k;

    if(l == r && l > 1) {
        cout << "YES" << endl;
        return;
    }

    if(l % 2) cout << ((ceil((r - l + 1) / (double)2) <= k) ? "YES" : "NO") << endl;
    else
        cout << ((floor((r - l + 1) / (double)2) <= k) ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}