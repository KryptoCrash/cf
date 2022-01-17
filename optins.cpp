/*
TODO: Fix case where the best place to put something is before all values in ai

(might work to change how the psum and blocks work)
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
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

    vi psum(n + 1);

    for (ll i = 0; i <= n; i++) {
        psum[i] = i;
    }

    ll sq = sqrt(n + 1) + 1;

    // min for block, min index for block, sum of total block updates
    vector<array<ll, 3>> block(sq);

    for(ll i = 0; i < sq; i++) {
        block[i] = {(ll)1e9, -1, 0};
    }

    for (ll i = 0; i < sq; i++) {
        for (ll j = i * sq; j < min(n + 1, (i+1)*sq); j++) {
            if (psum[j] <= block[i][0]) {
                block[i][0] = psum[j];
                block[i][1] = j;
            }
        }
    }

    function<void(ll, ll)> add_suf = [&](ll l, ll d) {
        // add in block
        ll cur_block = l / sq;
        ll cur_idx = l % sq;

        for (ll i = cur_block * sq + cur_idx; i < min(n + 1, (cur_block + 1) * sq); i++) {
            psum[i] += d;
            if (psum[i] <= block[cur_block][0]) {
                block[cur_block][0] = psum[i];
                block[cur_block][1] = i;
            }
        }

        // add over blocks
        for (ll i = cur_block + 1; i < sq; i++) {
            block[i][2] += d;
        }
    };

    function<ll()> min_idx = [&]() {
        ll mn = 1e9;
        ll mn_idx = -1;
        for (ll i = 0; i < sq; i++) {
            ll mn_block = block[i][0] + block[i][2];

            if (mn_block <= mn) mn = mn_block, mn_idx = block[i][1];
        }

        assert(mn_idx != -1);

        return mn_idx;
    };

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

            add_suf(i+1, dif);
        }

        path[c] = min_idx();
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