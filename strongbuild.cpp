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

    vector<vi> a(n + 1, vi(2e5 + 8));
    vi bestpath;
    bestpath.push_back(0);
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        bestpath.push_back(c);
        for (int j = 1; j <= c; j++) {
            cin >> a[i][j];
        }
    }

    ll m;
    cin >> m;

    set<vector<ll>> bb;
    for (ll i = 0; i < m; i++) {
        vector<ll> cur;
        cur.push_back(0);
        for (int j = 1; j <= n; j++) {
            int blah;
            cin >> blah;

            cur.push_back(blah);
        }

        bb.insert(cur);
    }

    ll best = 0;
    set<vector<ll>> gg;
    for (vi b : bb) {
        for (int j = 1; j <= n; j++) {
            if(b[j] != 1) {
                b[j]--;
                if (bb.find(b) == bb.end()) gg.insert(b);
                b[j]++;
            }
        }
    }

    vi besti;
    for (vi g : gg) {
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += a[i][g[i]];
        }
        if(sum > best) {
            best = sum;
            besti = g;
        }
    }

    if (bb.find(bestpath) == bb.end()) besti = bestpath;

    for(int i : besti) {
        if(i != 0) cout << i << " ";
    }

    return 0;
}