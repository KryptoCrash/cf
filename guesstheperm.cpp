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

    function<int(int, int)> query = [&](int l, int r) {
        int ans = 0;
        cout << "? " << l << " " << r << endl;
        cin >> ans;
        return ans;
    };

    int mx = query(1, n);

    int lo = 1;
    int hi = n;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (query(mid, n) < mx)
            hi = mid - 1;
        else
            lo = mid + 1;
    }

    ll i = hi;

    assert(i != n);

    ll dif = query(i, n) - query(i + 1, n);

    ll j = i + 1 + dif;

    dif = query(j, n) - query(j + 1, n);

    ll k = j + dif;

    cout << "! " << i << " " << j << " " << k << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}