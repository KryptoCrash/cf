#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;


void solve() {
    ll n;
    cin >> n;

    vector<ll> left(n);

    vector<set<ll>> adj(n);

    for (ll i = 0; i < n; i++) {
        ll k;
        cin >> k;
        left[i] = k;
        for (ll j = 0; j < k; j++) {
            ll v;
            cin >> v;
            v--;
            adj[v].insert(i);
        }
    }

    vector<bool> visit(n, false);

    priority_queue<array<ll, 3>> pq;
    ll ans = 0;
    ll vis_left = n;

    for (ll i = 0; i < n; i++) {
        if (left[i] == 0) {
            pq.push({-i, 1, i});
            vis_left--;
            visit[i] = true;
        }
    }

    while (!pq.empty()) {
        array<ll, 3> v = pq.top();
        pq.pop();

        ll dist = -v[0];
        ll iter = v[1];
        ans = iter;
        ll node = v[2];

        //cout << dist << " " << iter << " " << node << endl;

        for(ll nxt : adj[node]) {
            if (visit[nxt]) continue;
            //cout << "NEXT: " << nxt << endl;

            left[nxt]--;
            if(left[nxt] == 0) {
                if(nxt < node) {
                    pq.push({-(dist + n - node + nxt), iter + 1, nxt});
                } else {
                    pq.push({-(dist + nxt - node), iter, nxt});
                }

                visit[nxt] = true;
            }
        }
    }
    //cout << endl;

    for(bool i : visit) {
        //cout << "VISIT> " << i << endl;
        if (i == false) {
            cout << -1 << endl;
            return;
        }
    }
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