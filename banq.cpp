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

    map<ll, priority_queue<array<ll, 3>>> lin;
    vi x(n);
    vi y(n);
    for (ll i = 0; i < n; i++) {
        ll a, b, m;
        cin >> a >> b >> m;
        x[i] = a;
        y[i] = b;
        ll left = a + b - m;
        ll mina = max(0LL, a - m);
        ll maxa = a - max(0LL, -(b - m));

        lin[left].push({-mina, 1, i});
        lin[left].push({-maxa, -1, i});
    }

    vb vis(n);
    vpi ans(n);
    ll tot = 0;

    for(auto l : lin) {
        priority_queue<array<ll, 3>> ev = l.second;
        ll left = l.first;
        stack<ll> waiting;

        while(!ev.empty()) {
            array<ll, 3> ar = ev.top();
            ev.pop();

            ll v = -ar[0];
            ll tp = ar[1];
            ll idx = ar[2];

            if (tp == 1) waiting.push(idx);
            else {
                if (vis[idx]) continue;
                tot++;
                while(!waiting.empty()) {
                    ll i = waiting.top();
                    vis[i] = true;
                    ans[i] = {x[i] - v, y[i] - (left - v)};
                    waiting.pop();
                }
            }
        }
    }

    cout << tot << endl;

    for(pi i : ans) {
        cout << i.first << " " << i.second << endl;
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