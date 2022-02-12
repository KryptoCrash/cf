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

    ll n;
    cin >> n;

    if(n < 3) {
        cout << "2\n1 1\n1 2\n1 1\n1 2\n";
        return 0;
    }

    if(n < 4) {
        cout << "4\n1 3\n1 1\n1 1\n1 2\n1 1\n1 3\n1 2\n1 3\n";
        return 0;
    }

    if(n < 5) {
        cout << "5\n1 3\n1 4\n1 2\n2 3 4\n2 1 4\n1 2\n1 1\n2 3 4\n2 3 4\n1 1\n";
        return 0;
    }

    vector<vi> g(n, vi(n, -1));

    g[0][1] = 0;
    g[2][3] = 1;
    g[0][2] = g[0][3] = g[1][2] = g[1][3] = 2;

    for(ll id = 0; ; id++) {
        ll sz = 3 * (1 << id);
        if (sz > n) break;
        // fill first section
        for (ll i = 0; i < sz; i++) {
            for (ll j = 1; j <= sz; j++) {
                if(i + sz < n && j + sz < n) g[i + sz][j + sz] = (g[i][j] == 2*id + 2 ? 2*id + 3 : g[i][j]);
            }
        }
        for (ll i = 0; i < sz; i++) {
            for (ll j = 1; j <= sz; j++) {
                if (i < n && j + sz < n) g[i][j + sz] = 2*id + 4;
            }
        }
    };

    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n - 1; j++) {
            g[j + 1][i] = g[i][j] + 25;
        }
    }

    for (ll i = 1; i < n; i++) {
        g[i][i - 1] = -1;
    }

    vector<vector<vb>> moves(50, vector<vb>(2, vb(n)));

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (g[i][j] != -1) {
                moves[g[i][j]][0][i] = true;
                moves[g[i][j]][1][j] = true;
            }
        }
    }

    ll cnt = 0;
    vb works(50);
    vector<vi> sum(50, vi(2));
    for (ll i = 0; i < 50; i++) {
        for (int k = 0; k < 2; k++) {
            for (int j = 0; j < n; j++) {
                sum[i][k] += moves[i][k][j];
            }
        }
        if (sum[i][0] > 0 || sum[i][1] > 0) cnt++, works[i]=true;
    }

    cout << cnt << endl;
    for (int i = 0; i < 50; i++) {
        if (!works[i]) continue;
        cout << sum[i][0] << " ";
        for (int j = 0; j < n; j++) {
            if (moves[i][0][j]) cout << j + 1 << " ";
        }
        cout << endl;
        cout << sum[i][1] << " ";
        for (int j = 0; j < n; j++) {
            if (moves[i][1][j]) cout << j + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}