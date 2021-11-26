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
    ll root = 0;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        if (a[i] == i) root = i;
    }

    vector<set<ll>> ed(n);
    for (ll i = 0; i < n; i++) {
        if (i == root) continue;
        ed[a[i]].insert(i);
    }

    vi p(n);
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        mp[p[i]] = i;
    }

    auto compare = [&](ll x, ll y) {
        return mp[x] > mp[y];
    };

    priority_queue<ll, vector<ll>, decltype(compare)> pq(compare);
    pq.push(root);

    ll i = 0;

    vi sum(n);
    vi edw(n);

    while(!pq.empty()) {
        ll top = pq.top();
        pq.pop();

        if(top != p[i]) {
            cout << -1 << endl;
            return;
        }

        if(top != root) {
            ll par = sum[a[top]];
            if(i - par <= 0) {
                cout << -1 << endl;
                return;
            }
            sum[top] = i;
            edw[top] = i - par;
        }

        for(ll child : ed[top]) {
            pq.push(child);
        }

        i++;
    }

    for(ll w : edw) {
        cout << w << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}