#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int solve() {
    int x, y;
    cin >> x >> y;

    string s;
    cin >> ws;
    getline(cin, s);

    stringstream is(s);

    int n = s.length();

    vector<char> a(n);
    for (int i = 0; i < n; i++) {
        is >> a[i];
    }

    vector<pair<int, int>> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = {INF, INF};
    }

    if (a[0] != 'J') dp[0].first = 0;
    if (a[0] != 'C') dp[0].second = 0;

    for (int i = 0; i < n - 1; i++) {
        // you want to make next one c
        if (a[i + 1] != 'J') {
            // sum is either curr c
            dp[i + 1].first = min(dp[i + 1].first, dp[i].first);
            // or j + y
            dp[i + 1].first = min(dp[i + 1].first, dp[i].second + y);
        }
        // you want to make next one j
        if (a[i + 1] != 'C') {
            // sum is either curr j
            dp[i + 1].second = min(dp[i + 1].second, dp[i].second);
            // or c + x
            dp[i + 1].second = min(dp[i + 1].second, dp[i].first + x);
        }
    }

    return min(dp[n - 1].first, dp[n - 1].second);
}

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": " << solve() << endl;
    }

    return 0;
}
