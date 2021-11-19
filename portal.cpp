#include <bits/stdc++.h>
using namespace std;

using ll = int;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vi> a(n, vi(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }

    // get i+1 - j-1 empty at k
    vector<vector<vi>> sum_e(n, vector<vi>(n, vi(m)));
    for (int k = 0; k < m; k++) {
        vi psum(n + 1);
        for (int j = 0; j < n; j++) {
            psum[j + 1] = psum[j] + a[j][k];

            for (int i = 0; i < n; i++) {
                if(j > i) sum_e[i][j][k] = psum[j] - psum[i+1];
            }
        }
    }

    ll mn = 1e9;

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if (j - i < 4) continue;
            ll mx = -1e9;
            vi psum(m + 1);
            
            for(int k = 0; k < m; k++) {
                psum[k + 1] = psum[k] + sum_e[i][j][k] + (a[i][k] ^ 1) + (a[j][k] ^ 1);
            }
            for (int k = 0; k + 3 < m; k++) {
                mx = max(mx, psum[k + 1] - (max(0, j - i - 1) - sum_e[i][j][k]));
                mn = min(mn, psum[k + 3] - mx + (max(0,j - i - 1) - sum_e[i][j][k+3]));
            }
        }
    }

    cout << mn << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}