#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, q;
    cin >> n >> m >> q;

    function<bool(ll, ll)> in = [&](ll x, ll y) {
        if (x >= 0 && x < n && y >= 0 && y < m) return true;
        return false;
    };

    vector<vi> c(n + m + 2, vi(3));

    for (ll i = 0; i <= n + m + 1; i += 1)
        for (ll j = 0; j <= 2; j += 1)
            c[i][j] = j ? (i ? (c[i - 1][j - 1] + c[i - 1][j]) : 0) : (i ? 1 : 0);

    ll cnt = 0;
    // first precomp the amount of staircases
    // this can be done rather inefficiently
    for (ll i = 1; i < m; i++) {
        ll x = 0;
        ll y = i;

        ll len = 0;

        ll d = 0;
        while (in(x, y)) {
            if (d == 0)
                x++;
            else
                y++;
            len++;

            d = !d;
        }

        cnt += c[len + 2][2];
    }

    for (ll i = 1; i < n; i++) {
        ll x = i;
        ll y = 0;

        ll len = 0;

        ll d = 1;
        while (in(x, y)) {
            if (d == 0)
                x++;
            else
                y++;
            len++;
            d = !d;
        }

        cnt += c[len + 2][2];
    }
    cnt += n * m;
    // now do queries fast because not much is affected per query
    vector<vb> grid(n, vb(m));
    for (ll i = 0; i < q; i++) {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        ll new_val = !grid[x][y];
        grid[x][y] = false;
        ll change = 0;
        array<ll, 2> cur = {x, y};
        for (ll d = 0; d < 2; d++) {
            ll cur_d = d;
            ll cnt1, cnt2;
            cnt1 = cnt2 = 0;
            cur = {x, y};
            while (in(cur[0], cur[1]) && !grid[cur[0]][cur[1]]) {
                cnt1++;
                cur_d = !cur_d;
                cur[cur_d]--;
            }
            cur_d = !d;
            cur = {x, y};

            while (in(cur[0], cur[1]) && !grid[cur[0]][cur[1]]) {
                cnt2++;
                cur_d = !cur_d;
                cur[cur_d]++;
            }

            change += cnt1 * cnt2 - 1;
        }

        change += 1;

        grid[x][y] = new_val;

        if (new_val) {
            cnt -= change;
        } else
            cnt += change;

        cout << cnt << endl;
    }

    return 0;
}