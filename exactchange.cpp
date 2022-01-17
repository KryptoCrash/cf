#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

const ll INF = 1e9;

void solve() {
    ll n;
    cin >> n;

    vi a(n);
    ll mx = 0;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i] / 3);
    }

    ll best = INF;

    for (ll i = 0; i < 3; i++) {
        for (ll j = 0; j < 3; j++) {
            for (ll k = max(0LL, mx - 4); k <= mx; k++) {
                ll cur_tot = i + j + k;
                bool works = true;
                for (ll l = 0; l < n; l++) {
                    bool mightwork = false;
                    for (ll x = 0; x <= i; x++) {
                        for (ll y = 0; y <= j; y++) {
                            ll v = (a[l] - x - 2 * y);
                            if (v >= 0 && v % 3 == 0 && v / 3 <= k) mightwork = true;
                        }
                    }
                    if (!mightwork) works = false;
                }
                if (works) best = min(best, cur_tot);
            }
        }
    }

    cout << best << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}