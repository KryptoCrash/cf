#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    vi cost(n);
    for (ll i = 0; i < n; i++) {
        cin >> cost[i];
    }

    map<pi, array<ll, 3>> ed;
    vector<set<pi>> lad(n);

    vi b(n);
    for (ll i = 0; i < k; i++) {
        ll x, y, z, w, c;

        cin >> x >> y >> z >> w >> c;
        x--, y--, z--, w--;
        ed[{x, y}] = {z, w, -c};
        lad[x].insert({y, 1});
        lad[z].insert({w, 0});
    }

    lad[n - 1].insert({m - 1, 0});

    priority_queue<array<ll, 4>> pq;
    pq.push({0, 0, 0, 0});
    vector<vector<array<ll, 2>>> vis(n, vector<array<ll, 2>>(m, array<ll, 2>{0, 0}));
    vis[0][0][0] = true;

    ll ans = 1e9;
    bool pos = 0;
    while (!pq.empty()) {
        array<ll, 4> top = pq.top();
        pq.pop();
        ll x = top[1];
        ll y = top[2];
        ll dist = -top[0];
        ll tp = top[3];
        if (x == n - 1 && y == m - 1) {
            ans = dist;
            pos = 1;
            break;
        }

        auto it = lad[x].find({y, tp});
        if (it != lad[x].begin()) {
            it--;
            if (!vis[x][(*it).first][(*it).second]) {
                pq.push({-(dist + abs(y - (*it).first) * cost[x]), x, (*it).first, (*it).second});
                vis[x][(*it).first][(*it).second] = true;
            }

            it++;
        }
        if (it != lad[x].end()) {
            it++;
            if (it != lad[x].end()) {
                if (!vis[x][(*it).first][(*it).second]) {
                    pq.push({-(dist + abs(y - (*it).first) * cost[x]), x, (*it).first, (*it).second});
                    vis[x][(*it).first][(*it).second] = true;
                }
            }
            it--;
        }

        if (tp == 1) {
            if (!vis[ed[{x, y}][0]][ed[{x, y}][1]][0LL]) {
                pq.push({-(dist + ed[{x, y}][2]), ed[{x, y}][0], ed[{x, y}][1], 0LL});
                vis[ed[{x, y}][0]][ed[{x, y}][1]][0LL] = true;
            }
        }
    }

    if (!pos)
        cout << "NO ESCAPE" << endl;
    else
        cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}