#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

void solve() {
    ll hc, ac, hm, am;

    cin >> hc >> ac >> hm >> am;

    ll k, w, a;
    cin >> k >> w >> a;

    bool works = false;
    for (ll x = 0; x <= k; x++) {
        ll fk = ceil(hm / (double)(ac + x * w));
        ll sk = ceil((hc + (k - x) * a) / (double)am);

        if (fk <= sk) works = true;
    }

    cout << (works ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}