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

    vector<array<int, 3>> qu(n);
    for (int i = 0; i < n; i++) {
        int t;
        int x, y;
        x = y = 0;
        cin >> t;
        if (t == 1) {
            cin >> x;
        } else {
            cin >> x >> y;
        }
        qu[i] = {t, x, y};
    }

    vi path;
    vi look(5e5 + 8);
    for (int i = 0; i < 5e5 + 8; i++) {
        look[i] = i;
    }
    for (int i = n - 1; i >= 0; i--) {
        int t = qu[i][0];
        int x = qu[i][1];
        int y = qu[i][2];

        if(t==1) {
            path.push_back(look[x]);
        } else {
            look[x] = look[y];
        }
    }

    reverse(path.begin(), path.end());
    for (int i : path) {
        cout << i << " ";
    }

    return 0;
}