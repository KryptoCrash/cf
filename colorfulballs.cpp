#include <bits/stdc++.h>

using namespace std;

const int maxn = 100 + 8;

int solve() {
    int n;
    cin >> n;

    multiset<int> a;

    for (int i = 0; i < n; i++) {
        int curr;
        cin >> curr;
        a.insert(curr);
    }

    int mx = 0;
    for (int e : a) {
        mx = max(mx, (int)a.count(e));
    }
    return mx;
}

int main() {
    int t;
    cin >> t;
    while (t--) cout << solve() << endl;

    return 0;
}