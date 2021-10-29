#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;

int solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int sum = 0;

    for (int i = 0; i < n; i++) {
        auto st = a.begin() + i;
        auto best = min_element(st, a.end());

        sum += best - st + 1;
        reverse(st, best + 1);
    }

    return sum - 1;
}

int main() {
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": " << solve() << endl;
    }

    return 0;
}