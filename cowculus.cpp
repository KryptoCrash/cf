#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;

    ll good = 0, bad = 0;
    vi a(n);
    vi g;
    vi b;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] >= 93) {
            good++;
            g.push_back(a[i]);
        } else {
            bad++;
            b.push_back(a[i]);
        }
    }

    sort(g.begin(), g.end());
    sort(b.begin(), b.end());

    ll ok = good * k;

    ll val = max(0ll, bad - ok);

    vi ans;

    for (int i = 0; i < val; i++) {
        cout << b[i] << " ";
    }

    ll l, r;
    l = 0;
    r = val;

    while(l < g.size()) {
        cout << g[l++] << " ";
        ll up_bound = min((ll)b.size(), r + k);

        while(r < up_bound) {
            cout << b[r++] << " ";
        }
    }

    return 0;
}