/*
TODO: Fix case where the best place to put something is before all values in ai

(might work to change how the psum and blocks work)
*/

#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace std;
using namespace atcoder;

using ll = int;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

struct FenwickTree {
    vector<ll> bit;  // binary indexed tree
    ll n;

    FenwickTree(ll n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<ll> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    ll sum(ll r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    ll sum(ll l, ll r) {
        return sum(r) - sum(l - 1);
    }

    void add(ll idx, ll delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

pi mn(pi a, pi b) {
    if (a.first == b.first) return a.second > b.second ? a : b;
    return a.first < b.first ? a : b;
}

pi e() {
    return {1e9, -1};
}

pi mapping(ll d, pi x) {
    return {x.first + d, x.second};
}

ll composition(ll f, ll g) {
    return f + g;
}

ll id() {
    return 0;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    priority_queue<array<ll, 3>> ev;

    vi a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        ev.push({-a[i], i, 1});
    }

    vi b(m);
    for (ll i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(b.begin(), b.end());

    vi swap(n, 1);

    vi path(m);

    vpi psum(n + 1);

    for (ll i = 0; i <= n; i++) {
        psum[i] = {i, i};
    }

    lazy_segtree<pi, mn, e, ll, mapping, composition, id> seg(psum);

    for (ll c = 0; c < m; c++) {
        while (!ev.empty()) {
            array<ll, 3> top = ev.top();
            ll v = -top[0];
            ll i = top[1];
            ll tp = top[2];
            if (v > b[c]) break;
            ev.pop();
            ll dif;
            if (v == b[c] && tp == 1) dif = -swap[i], swap[i] = 0, ev.push({-(v + 1), i, 0});
            if (v < b[c] || (v == b[c] && tp == 0)) dif = -1 - swap[i], swap[i] = -1;
            seg.apply(i + 1, n + 1, dif);
        }

        path[c] = seg.all_prod().second;
    }

    // construct optimal array
    vpi opt;

    for (ll i = 0; i < n; i++) {
        opt.push_back({i, -1});
    }

    for (ll i = 0; i < m; i++) {
        opt.push_back({path[i]-1, i});
    }

    sort(opt.begin(), opt.end());

    vpi actual_opt(opt.size());
    for (ll i = 0; i < opt.size(); i++) {
        pi v = opt[i];
        actual_opt[i] = {v.second == -1 ? a[v.first] : b[v.second], i};
    }

    sort(actual_opt.begin(), actual_opt.end());

    map<ll, ll> coord;

    for(ll i = 0; i < opt.size(); i++) {
        ll v = actual_opt[i].first;

        coord[v] = i;
    }

    sort(actual_opt.begin(), actual_opt.end(), [](pi x, pi y) { return x.second < y.second; });

    // calc inversions on optimal array
    FenwickTree ft(opt.size() + 8);

    ll ans = 0;
    for (pi i : actual_opt) {
        ll v = coord[i.first];
        // find all things > v
        ans += ft.sum(v + 1, opt.size()+2);
        // add v to the thing
        ft.add(v, 1);
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