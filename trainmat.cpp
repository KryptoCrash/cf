#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

int main() {
    ll n, m;
    cin >> n >> m;

    vi a(n);
    vi b(n);
    for (ll i = 0; i < n; i++) {
        scanf("%d%d", &a[i], &b[i]);
    }

    ll ans = 0;
    ll sq = (ll)sqrt(m);
    vector<vi> upd(sq, vi(sq));
    vi rsum(sq);
    vi psum(m);
    vi st(n);
    for (ll i = 0; i < m; i++) {
        ll op, k;
        scanf("%d%d", &op, &k);
        k--;
        ll x = a[k];
        ll y = b[k];

        ll im = i % (x + y);

        if (op == 1) {
            ans += psum[i];

            for (ll j = 1; j < sq; j++) {
                rsum[j] += upd[j][i % j];
                ans += rsum[j];
            }
            st[k] = i;
            if (x + y >= sq) {
                for (ll j = i + x; j < m; j += x + y) {
                    psum[j]++;
                    if (j + y < m) psum[j + y]--;
                }
            } else {
                upd[x + y][(i + x) % (x + y)]++;
                upd[x + y][im]--;
            }
        } else {
            ll v = st[k];
            if (x + y >= sq) {
                bool works = false;
                for (ll j = v + x; j < m; j += x + y) {
                    psum[j]--;
                    if (j + y < m) psum[j + y]++;
                    if (i >= j && i < j + y) {
                        works = true;
                    }
                }
                if (works) ans--;
            } else {
                ll spt = (v + x) % (x + y);
                ll ept = v % (x + y);
                if (spt < ept && im >= spt && im < ept) {
                    ans--;
                }
                if (ept > spt && (im >= spt || im < ept)) {
                    ans--;
                }

                upd[x + y][spt]--;
                upd[x + y][ept]++;
            }
            ans += psum[i];

            for (ll j = 1; j < sq; j++) {
                rsum[j] += upd[j][i % j];
                ans += rsum[j];
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}