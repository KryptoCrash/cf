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

    ll m;
    cin >> m;

    vi a(n);
    map<ll, ll> cnt;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    map<ll, set<ll>> ed;

    for (ll i = 0; i < m; i++) {
        ll x, y;
        ed[x].insert(y);
        ed[y].insert(x);
    }

    for (ll i = 0; i < n; i++) {
        ll x = a[i];
        // minimize cnt[x]*x + cnt[y]*y + cnt[x]*y + cnt[y]*x
        stack<pi> st;
        for(ll y : ed[x]) {
            st.push()
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}