#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // calc cost of each place
    vector<ll> c(20);
    int r_mx = 0;
    int pt = 0;
    ll cur_k = 0;
    for (int i = 0; i < 20; i++) {
        while (true) {
            if (pt + 1 >= n) break;
            if (a[pt + 1] > i) {
                break;
            }
            pt++;
        }
        r_mx = max(r_mx, a[pt]);
        c[i] = (ll)pow(10,i - r_mx);
        cur_k += 9 * c[i];
    }

    ll ans = 0;

    for (int p = 19; p >= 0; p--) {
        for (int d = 9; d > 0; d--) {
            cur_k -= c[p];
            if (!(cur_k > k)) {
                cur_k += c[p];
                ans += (ll)pow(10, p) * d;
                break;
            }
        }
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) solve();
}