#include <bits/stdc++.h>
using namespace std;


using ll = long long;
using db = long double;  // or double, if TL is tight
using str = string;      // yay python!

const ll inf = 1e9;

// pairs
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
#define mp make_pair
#define f first
#define s second

#define tcT template <class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;

// vectors
// oops size(x), rbegin(x), rend(x) need C++17
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()

#define lb lower_bound
#define ub upper_bound
tcT > int lwb(V<T>& a, const T& b) { return int(lb(all(a), b) - bg(a)); }
tcT > int upb(V<T>& a, const T& b) { return int(ub(all(a), b) - bg(a)); }

// loops
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto& a : x)

const int MOD = 1e9 + 7;  // 998244353;
const int MX = 2e5 + 5;
const ll BIG = 1e18;  // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};  // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

/**
 * Description: 1D range increment and sum query.
 * Source: USACO Counting Haybales
 * Verification: SPOJ Horrible
 */

tcT, int SZ > struct LazySeg {
    const T ID = 0;
    T cmb(T a, T b) { return a + b; }
    T seg[2 * SZ], lazy[2 * SZ];
    LazySeg() { F0R(i, 2 * SZ)
                seg[i] = lazy[i] = ID; }
    void push(int ind, int L, int R) {        /// modify values for current node
        seg[ind] += (R - L + 1) * lazy[ind];  // dependent on operation
        if (L != R) F0R(i, 2)
                    lazy[2 * ind + i] += lazy[ind];  /// prop to children
        lazy[ind] = 0;
    }  // recalc values for current node
    void pull(int ind) { seg[ind] = cmb(seg[2 * ind], seg[2 * ind + 1]); }
    void build() { ROF(i, 1, SZ)
                   pull(i); }
    void upd(int lo, int hi, T inc, int ind = 1, int L = 0, int R = SZ - 1) {
        push(ind, L, R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] = inc;
            push(ind, L, R);
            return;
        }
        int M = (L + R) / 2;
        upd(lo, hi, inc, 2 * ind, L, M);
        upd(lo, hi, inc, 2 * ind + 1, M + 1, R);
        pull(ind);
    }
    T query(int lo, int hi, int ind = 1, int L = 0, int R = SZ - 1) {
        push(ind, L, R);
        if (lo > R || L > hi) return ID;
        if (lo <= L && R <= hi) return seg[ind];
        int M = (L + R) / 2;
        return cmb(query(lo, hi, 2 * ind, L, M),
                   query(lo, hi, 2 * ind + 1, M + 1, R));
    }
};

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vector<array<ll, 3>> a(m);
    vi coord;
    for (int i = 0; i < m; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        coord.push_back(a[i][1]);
        coord.push_back(a[i][2]);
    }

    sort(a.begin(), a.end());
    sort(coord.begin(), coord.end());
    coord.erase(unique(all(coord)), end(coord));

    //LazySeg<ll, (int)(2 << 20)> st;

    for (int i = 0; i <= m; i++) {
        // get min of segtree
        cout << *lower_bound(all(coord), a[i][1]) <<endl;
        //ll seg_min = st.query(lower_bound(all(coord), a[i][1]) - coord.begin(), lower_bound(all(coord), a[i][2]) - coord.begin());
    }

    return 0;
}