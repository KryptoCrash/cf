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

    ll n, m;
    cin >> n >> m;

    vector<set<array<ll, 3>>> ch(m);
    vpi p(n);

    for (ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        p[i] = {a, b};

        ch[a].insert({b, i, 0});
        ch[b].insert({a, i, 1});
    }

    vb vis(n);
    vb done(m);
    vi path;
    ll ans = 0;

    function<void(ll, bool)> dfs = [&](ll v, bool first) {
        if (vis[v]) return;

        vis[v] = true;
        path.push_back(v + 1);

        ll f = p[v].first;
        ll s = p[v].second;

        if(first && !done[f]) {
            ans++;
            done[f] = true;

            for(auto i : ch[f]) {
                if (i[1] == v) continue;
                dfs(i[1], i[2]);
            }
        } else if(!done[s]) {
            ans++;
            done[s] = true;
            
            for(auto i : ch[s]) {
                if (i[1] == v) continue;
                dfs(i[1], i[2]);
            }
        }
        
    };

    for (ll i = 0; i < n; i++) {
        if (vis[i]) continue;
        dfs(i, true);
    }

    cout << n - ans << endl;

    for(ll i : path) {
        cout << i << endl;
    }

    return 0;
}