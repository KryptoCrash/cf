#include <bits/stdc++.h>

using namespace std;

const int maxn = 2500 + 8;
using ll = long long;
using pi = pair<int, int>;

ll psum[maxn][maxn];

bool ycmp(pi a, pi b) { return a.second < b.second; }

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;

    pi p[maxn];
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; i++) {
        p[i].first = i;
    }

    sort(p + 1, p + n + 1, ycmp);
    for (int i = 1; i <= n; i++) p[i].second = i;

    // construct psum
    memset(psum, 0, sizeof(psum));

    for (int i = 1; i <= n; i++) {
        psum[p[i].first][p[i].second] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            psum[i][j] += psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
        }
    }

    ll ans = 0;

    // find all pairs of cows
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x1 = min(p[i].first, p[j].first);
            int x2 = max(p[i].first, p[j].first);
            int y1 = min(p[i].second, p[j].second);
            int y2 = max(p[i].second, p[j].second);

            int lsum = psum[x1][y2] - psum[x1][y1 - 1];
            int csum = psum[x2][y2] - psum[x2][y1 - 1];
            int rsum = psum[n][y2] - psum[n][y1 - 1] + 1;

            ans += lsum * (rsum - csum);
        }
    }

    cout << (ans - n) / 2 + n + 1 << endl;

    return 0;
}