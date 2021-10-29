#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

const int INF = 2 * 1e9;

void solve() {
    int n;
    int k;
    cin >> n;
    cin >> k;

    int i = n;
    while(true) {
        bool vis[10];
        memset(vis, false, sizeof(vis));
        for (int c : to_string(i)) {
            vis[c - '0'] = true;
        }
        int cnt = 0;
        for (int g = 0; g <= 9; g++) {
            cnt += vis[g];
        }
        if (cnt <= k) {
            cout << i << endl;
            break;
        }

        i++;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}