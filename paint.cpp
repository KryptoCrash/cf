#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

vector<vector<vector<int>>> memo;
vi a;

int dp(int l, int r) {
    for (int i = l; i < r - 1; i++) {
        
    }
}

void solve() {
    int n;
    cin >> n;
    memo = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(3, 0)));
    a = vi(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}