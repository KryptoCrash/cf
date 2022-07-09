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

    ll s;
    cin >> s;


    vpi a(n);
    ll mnsum = 0;
    for (ll i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        mnsum += a[i].first;
    }

    function<bool(ll)> ok = [&](ll m) {
        vpi st;
        ll mxl = 0;
        for (ll i = 0; i < n; i++) {
            if(a[i].second >= m && a[i].first <= m) {
                st.push_back(a[i]);
            } else {
                mxl = max(mxl, a[i].first);
            }
        }

        if(mxl )

        sort(st.begin(), st.end());
        reverse(st.begin(), st.end());

        ll needed = n / 2 + 1;

        if(st.size() < needed) return false;

        ll used = mnsum;

        for (ll i = 0; i < needed; i++) {
            used += (m - st[i].first);
        }

        if(used <= s) return true;
        return false;
    };

    ll lo = 0;
    ll hi = 1e15;
    
    while (lo < hi) {
        ll mid = (lo + hi + 1) / 2;
        if (ok(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    cout << lo << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}