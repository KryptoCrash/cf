#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

const ll maxn = (ll)pow(2, 10);

ll inv(ll val) {
    if (val == 0) return 1;
    ll x = log2(val) + 1;

    for (ll i = 0; i < x; i++) val = (val ^ (1 << i));

    return val;
}

void solve() {
    ll start;
    ll end;
    cin >> start;
    cin >> end;

    ll s, e;
    s = stoi(to_string(start), nullptr, 2);
    e = stoi(to_string(end), nullptr, 2);

    // bfs on states
    queue<ll> ready;
    vi dist(maxn, INT_MAX);
    ready.push(s);
    dist[s] = 0;
    while (!ready.empty()) {
        ll x = ready.front();
        ready.pop();
        ll notx = inv(x);
        ll dx = x << 1;
        if (notx < maxn && dist[notx] == INT_MAX) {
            dist[notx] = dist[x] + 1;
            ready.push(notx);
        }
        if (dx < maxn && dist[dx] == INT_MAX) {
            dist[dx] = dist[x] + 1;
            ready.push(dx);
        }
    }

    if (dist[e] == INT_MAX) {
        cout << "IMPOSSIBLE";
    } else {
        cout << dist[e];
    }
}

int main() {
    ll t;
    cin >> t;

    for (ll i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();

        cout << endl;
    }

    return 0;
}