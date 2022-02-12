#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

vi dist(1e3+1, 1e9);

void solve() {
    ll n, k;
    cin >> n >> k;

    vi a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    vi c(n);
    for(ll i = 0; i < n; i++) {
        cin >> c[i];
    }

    map<ll, ll> dp1;
    dp1[0] = 0;
    map<ll, ll> dp2;
    ll best = 0;
    for (ll i = 0; i <= n; i++) {
        for (pi dp : dp1) {
            ll w = dp.first;
            ll v = dp.second;
            best = max(best, v);
            if (i == n) continue;
            // cost is dist[a[i]]

            // not use
            dp2[w] = max((dp2.find(w) != dp2.end() ? dp2[w] : 0), v);
            // use
            if (w + dist[a[i]] <= k) dp2[w + dist[a[i]]] = max((dp2.find(w + dist[a[i]]) != dp2.end() ? dp2[w + dist[a[i]]] : 0), v + c[i]);
        }
        dp1 = dp2;
        dp2.clear();
    }
    cout << best << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll mx = 1e3 + 1;
    vector<set<ll>> ed(1e3 + 1);

    for (ll i = 1; i < mx; i++) {
        for (ll x = 1; x < mx; x++) {
            if ((i + (i / x)) < mx) ed[i].insert(i + (i / x));
        }
    }
    vb vis(mx, false);
    queue<pi> q;
    q.push({1, 0});
    vis[1] = true;
    dist[1] = 0;

    while(!q.empty()) {
        pi top = q.front();

        q.pop();

        ll v = top.first;
        ll d = top.second;

        for(ll ch : ed[v]) {
            if(!vis[ch]) {
                vis[ch] = true;
                dist[ch] = d + 1;
                q.push({ch, dist[ch]}); 
            }
        }
    }
    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}