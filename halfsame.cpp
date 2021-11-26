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

    vi a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll mx = 0;

    map<ll, ll> mp;
    mp.clear();
    for (ll i = 0; i < n; i++) {
        mp[a[i]]++;
    }
    for (pair<ll, ll> val : mp) {
        if (val.second >= n / 2) {
            cout << -1 << endl;
            return;
        }
    }

    for (ll i = 0; i < n; i++) {
        map<ll, ll> cnt;
        ll dup = 0;
        cnt.clear();
        for (ll k = i + 1; k < n; k++) {
            ll diff = a[k] - a[i];
            if (diff == 0) dup++;
            for (ll j = 1; j * j <= diff; j++) {
                if (diff % j == 0) {
                    cnt[j]++;
                    if(j * j != diff) cnt[diff / j]++;
                }
            }
        }

        for (pair<ll, ll> v : cnt) {
            if (v.second+1+dup >= n / 2) mx = max(mx, v.first);
        }
    }

    cout << mx << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while (t--) solve();

    return 0;
}