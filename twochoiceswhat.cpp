#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 8;
int main() {
    int n, m;
    cin >> n >> m;

    bool is_odd[maxn];

    for (int i = 0; i < n; i++) {
        int num_ones = 0;
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c - '0' == 1) num_ones++;
        }
        is_odd[i] = num_ones % 2;
    }

    int psum_evens[maxn];
    int psum_odds[maxn];

    for (int i = n - 1; i > 0; i--) {
        if (is_odd[i]) {
            psum_odds[i - 1] = psum_odds[i] + 1;
            psum_evens[i - 1] = psum_evens[i];
        } else {
            psum_evens[i - 1] = psum_evens[i] + 1;
            psum_odds[i - 1] = psum_odds[i];
        }
    }

    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (is_odd[i])
            sum += psum_evens[i];
        else
            sum += psum_odds[i];
    }

    cout << sum << endl;

    return 0;
}