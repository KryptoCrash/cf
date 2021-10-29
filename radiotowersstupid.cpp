#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 5000;
const int mod = 998244353;

int main() {
    int n;
    cin >> n;

    int dp[maxn];

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= n; i++) {
        int par = i % 2;
        for (int j = 0; j <= n; j++) {
            if(j % 2 == par) continue;
            dp[j] += dp[i] + 1;
        }
    }

    cout << dp[n] << endl;

    return 0;
}