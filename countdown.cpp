#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

void solve() {
    int n;
    char c;
    cin >> n;
    int a;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> c;
        a = c - '0';
        ans += a;
        if (i != n - 1 && a != 0) ans++;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}