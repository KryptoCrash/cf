/* 
Vitamins: Bitmask DP
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000 + 42;
const int INF = 0x3f3f3f3f;
const int m_len = 1 << 3;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;

    int c[maxn];
    int bm[maxn];

    string curr;
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> curr;
        
        bool curr_bm[3] = {
            curr.find('A') < curr.length(),
            curr.find('B') < curr.length(),
            curr.find('C') < curr.length()
        };

        for (int j = 0; j < 3; j++) {
            bm[i] += curr_bm[j] << j;
        }
    }

    int dp[maxn][m_len];

    memset(dp, INF, sizeof(dp));

    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < m_len; mask++) {
            // If value at this location is INF, we know that it is impossible to get to this state
            if(dp[i][mask] == INF) continue;

            // Don't drink
            dp[i + 1][mask] = min(dp[i + 1][mask], dp[i][mask]);

            // Drink
            int c_mask = bm[i];
            int cost = c[i];
            dp[i + 1][mask | c_mask] = min(dp[i + 1][mask | c_mask], dp[i][mask] + cost);
        }
    }

    int res = dp[n][m_len - 1];

    cout << (res == INF ? -1 : res) << endl;

    return 0;
}