#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

const int maxn = 1e6 + 8;



int solve() {
    int n;
    cin >> n;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 3; i <= n; i++) {
        dp[i][i] = 1;
    }

    for (int i = 3; i < n; i++) {
        for (int j = 3; j < n; j++) {
            if(dp[i][j] == 0) continue;
            for (int k = 2;; k++) {
                int sum = i + j * k;
                if (sum > n) break;
                dp[sum][j * k] = max(dp[sum][j * k], dp[i][j] + 1);
            }
        }
    }

    int best = 0;
    for (int i = 3; i <= n; i++) {
        best = max(best, dp[n][i]);
    }

    return best;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "CASE #" << i << ": " << solve() << endl;
    }

    // precompute


    return 0;
}