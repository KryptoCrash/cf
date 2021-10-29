#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+4;

int main() {
    int n;
    cin >> n;

    int a[maxn];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int dp[maxn];
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        bool ok = (a[i+1] != a[i]) || (a[i+1] == a[i] && a[i] != a[i-1]);
        dp[i] = dp[i - 1] + (ok ? 1 : 0);
    }

    cout << dp[n - 1] << endl;

    return 0;
}