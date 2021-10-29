#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

const int mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll w, h;
    cin >> h >> w;

    vi diag(h + w - 1, 2);
    vector<char> di(h + w - 1, '.');

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c;
            cin >> c;
            if(c != '.') {
                if (di[i + j] == c) continue;
                else if(di[i + j] == '.') {
                    diag[i + j] = 1;
                    di[i + j] = c;
                } else
                    diag[i + j] = 0;
            }
        }
    }

    int ans = 1;

    for (int ch : diag) {
        ans *= ch;
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}