#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

const ll INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vi a(n + 1);
    vb exi(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i + 1];
        a[i + 1]--;
        if (a[i + 1] == -1) continue;
        exi[a[i + 1]] = true;
        a[i + 1] %= 2;
    }

    int num_0 = 0;
    int num_1 = 0;

    for(int i = 0; i < n; i++) {
        if(!exi[i]) {
            if(i % 2) {
                num_1++;
            } else
                num_0++;
        }
    }

    // index last elem in prefix, num of 1 in prefix USED, parity of last elem in prefix  
    vector<vector<vector<array<int, 2>>>> dp(n+1, vector<vector<array<int,2>>>(n, vector<array<int,2>>(n, array<int,2>{INF, INF})));

    dp[0][0][0][0] = 0;
    dp[0][0][0][1] = 0;

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int m = 0; m < n; m++) {
                for (int k = 0; k < 2; k++) {
                    if (dp[i][j][m][k] == INF) continue;
                    if (a[i + 1] == -1) {
                        // next thing unset
                        
                        // set to 1
                        if (j < num_1) dp[i + 1][j+1][m][1] = min(dp[i + 1][j+1][m][1], dp[i][j][m][k] + (k ^ 1));

                        // set to 0
                        if (m < num_0) dp[i + 1][j][m+1][0] = min(dp[i + 1][j][m+1][0], dp[i][j][m][k] + (k ^ 0));

                    } else if (a[i + 1] == 0) {
                        // next thing has parity of 0
                        dp[i + 1][j][m][0] = min(dp[i + 1][j][m][0], dp[i][j][m][k] + (k ^ 0));
                    } else if (a[i + 1] == 1) {
                        // next thing has parity of 1
                        dp[i + 1][j][m][1] = min(dp[i + 1][j][m][1], dp[i][j][m][k] + (k ^ 1));
                    }
                }
            }
        }
    }

    cout << min(dp[n][num_1][num_0][0], dp[n][num_1][num_0][1]) << endl;

    return 0;
}