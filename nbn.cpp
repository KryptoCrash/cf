#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

const int INF = 0x3f3f3f3f;

void solve() {
    string n;
    int k;
    int n_i;
    cin >> n;
    cin >> k;
    n_i = stoi(n);

    if (k == 1) {
        int lo = n[0];
        string ans;
        ans = "";
        for (char c : n) {
            ans += lo;
        }
        if(stoi(ans) < n_i) {
            ans = "";
            for (char c : n) {
                ans += lo + 1;
            }
        }

        cout << ans << "\n";
        return;
    }

    bool vis[10];
    memset(vis, false, sizeof(vis));
    for (char c : n) {
        vis[c - '0'] = true;
    }
    int cnt = 0;
    for (int i = 0; i <= 9; i++) {
        cnt += vis[i];
    }
    if (cnt <= 2) {
        cout << n << "\n";
        return;
    }

    // x, y, digit, goneUp?
    int dp[10][10][10][2];

    memset(dp, INF, sizeof(dp));
    

    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            dp[i][j][0][false] = n_i;
        }
    }

    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int d = 0; d < n.length(); d++) {
                for (int up = 0; up < 2; up++) {
                    if (dp[i][j][d][up] == INF) continue;

                    int a = n[d] - '0';

                    //cout << (i - a) * (int)pow(10, n.length() - d - 1) << endl;

                    if (up) {
                        dp[i][j][d + 1][up] = min(dp[i][j][d + 1][up], dp[i][j][d][up] + (i - a) * (int)pow(10, n.length() - d - 1));
                        dp[i][j][d + 1][up] = min(dp[i][j][d + 1][up], dp[i][j][d][up] + (j - a) * (int)pow(10, n.length() - d - 1));
                    } else {
                        if (i >= a) dp[i][j][d + 1][true ? i > a : false] = min(dp[i][j][d + 1][true ? i > a : false], dp[i][j][d][up] + (i - a) * (int)pow(10, n.length() - d - 1));
                        if (j >= a) dp[i][j][d + 1][true ? j > a : false] = min(dp[i][j][d + 1][true ? j > a : false], dp[i][j][d][up] + (j - a) * (int)pow(10, n.length() - d - 1));
                    }
                }
            }
        }
    }

    int best = INF;

    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            //cout << i << " " << j << endl;
            //cout << endl;
            best = min(best, dp[i][j][n.length()][true]);
        }
    }

    cout << best << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}