#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

map<ll, ll> dp;

#define trav(a, x) for (auto& a : x)

#define all(x) begin(x), end(x)

#define mp make_pair

struct DSU {
    vi e;
    void init(ll N) { e = vi(N, -1); }

    // get representive component, uses path compression

    ll get(ll x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

    bool sameSet(ll a, ll b) { return get(a) == get(b); }

    ll size(ll x) { return -e[get(x)]; }

    bool unite(ll x, ll y) {  // union by size

        x = get(x), y = get(y);
        if (x == y) return 0;

        if (e[x] > e[y]) swap(x, y);

        e[x] += e[y];
        e[y] = x;
        return 1;
    }
};

ll cnt = 0;

template <class T> T kruskal(ll N, vector<pair<T, pi>> ed) {
    sort(all(ed));

    T ans = 0;
    DSU D;
    D.init(N + 1);  // edges that unite are in MST

    trav(a, ed)

        if (D.unite(a.second.first, a.second.second)) {
        ans += a.first;

        cnt++;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    vector<pair<ll, pi>> edge;
    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        edge.push_back(mp(c, mp(a, b)));
    }

    

    ll p, k, a, b, c;
    cin >> p >> k >> a >> b >> c;

    vi qu(k);

    for (ll i = 0; i < p; i++) {
        cin >> qu[i];
    }

    for (ll i = p; i < k; i++) {
        qu[i] = (qu[i - 1] * a + b) % c;
    }

    ll ans = 0;

    for (ll i = 0; i < k; i++) {
        if (dp.find(qu[i]) != dp.end()) {
            ans ^= dp[qu[i]];
            continue;
        }

        vector<pair<ll, pi>> edg2;

        for(pair<ll, pi> ed : edge) {
            edg2.push_back(mp(abs(ed.first - qu[i]), ed.second));
        }
        ll balh = kruskal(n, edg2);
        dp[qu[i]] = balh;
        ans ^= balh;
    }

    cout << ans << endl;

    return 0;
}