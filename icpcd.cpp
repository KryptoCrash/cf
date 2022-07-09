#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

void solve() {
    string s;
    string t;
    cin >> s >> t;

    ll n = s.length();
    ll m = t.length();

    vector<vi> dp(n + 1, vi(m + 1, false));
    dp[0][0] = 1;

    for(int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (dp[i][j] == 0) continue;

            if (i < n && j < m && s[i] == t[j]) dp[i + 1][j + 1] = 1;

            if (i + 2 <= n && s.substr(i, 2) == "AA") dp[i + 2][j] = 1;
            if (i + 2 <= n && s.substr(i, 2) == "BB") dp[i + 2][j] = 1;
            if (i + 2 <= n && s.substr(i, 2) == "CC") dp[i + 2][j] = 1;
            if (i + 4 <= n && s.substr(i, 4) == "ABAB") dp[i + 4][j] = 1;
            if (i + 4 <= n && s.substr(i, 4) == "BCBC") dp[i + 4][j] = 1;

            if (j + 2 <= m && t.substr(j, 2) == "AA") dp[i][j + 2] = 1;
            if (j + 2 <= m && t.substr(j, 2) == "BB") dp[i][j + 2] = 1;
            if (j + 2 <= m && t.substr(j, 2) == "CC") dp[i][j + 2] = 1;
            if (j + 4 <= m && t.substr(j, 4) == "ABAB") dp[i][j + 4] = 1;
            if (j + 4 <= m && t.substr(j, 4) == "BCBC") dp[i][j + 4] = 1;
        }
    }

        if (dp[n][m])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}