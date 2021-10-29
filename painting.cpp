#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+4;

int n;

// max, segx, segy
array<int, 3> dp[maxn][2];
int a[maxn];

array<int, 3> apply(int i, int s, array<int, 3> t) {
    int mx = t[0];
    int seg = t[s + 1];

    array<int, 3> res;

    if(a[i] == seg) {
        res = t;
    } else {
        res[0] = mx + 1;
        res[1] = (s == 0 ? a[i] : t[1]);
        res[2] = (s == 1 ? a[i] : t[2]);
    }

    return res;
}

array<int, 3> recur(int i, int s) {
    if(dp[i][s][0] != -1) return dp[i][s];
    dp[i][s] = max(apply(i, s, recur(i - 1, 0)), apply(i, s, recur(i - 1, 1)));
    return dp[i][s];
}

int main(int argc, char const *argv[]) {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        dp[i][0] = {-1, -1, -1};
        dp[i][1] = {-1, -1, -1};
    }

    dp[0][0] = {0, 0, 0};
    dp[0][1] = {0, 0, 0};

    cout << max(apply(n, 0, recur(n, 0)), apply(n, 1, recur(n, 1)))[0] << endl;

    return 0;
}