#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vector<set<ll>> ed(n, set<ll>({}));
    for (ll i = 1; i < n; i++) {
        ll p;
        cin >> p;
        p--;
        ed[p].insert(i);
    }

    vi a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll max_ans = 0;

    function<pi(ll)> dfs = [&](ll v) {
        ll sum = a[v];
        ll sz = 0;
        for (ll child : ed[v]) {
            pi ar = dfs(child);
            sum += ar.first;
            sz += ar.second;
        }

        if (sz == 0) sz = 1;
        max_ans = max(max_ans, (ll)ceil((double)sum / (double)sz));
        return make_pair(sum, sz);
    };

    dfs(0);

    cout << max_ans << endl;

    return 0;
}