#include <bits/stdc++.h>

using namespace std;
const int maxn = 100 + 8;

int solve() {
    int n;
    cin >> n;

    int a[maxn];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int min = *min_element(a, a + n);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > min) sum++;
    }

    return sum;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cout << solve() << endl;
    }

    return 0;
}