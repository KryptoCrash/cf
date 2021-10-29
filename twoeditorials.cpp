#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int changes[maxn];
    memset(changes, 0, sizeof(changes));

    // get change array
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        changes[x]++;
        changes[y + 1]--;
    }

    // get num of part. waiting for editorial at pos i
    int active[maxn];
    memset(active, 0, sizeof(active));
    for (int i = 1; i <= n; i++) {
        active[i] = active[i - 1] + changes[i];
    }

    // get sliding window sum for k length segment
    int start[maxn];
    memset(start, 0, sizeof(start));
    int l = 1;
    int r = k;
    int curr_sum = 0;
    curr_sum = accumulate(active + 1, active + k + 1, curr_sum);
    start[1] = curr_sum;

    while (r < n) {
        l++, r++;
        curr_sum -= active[l - 1];
        curr_sum += active[r];
        start[l] = curr_sum;
    }

    // get max possible sum left of i and right of i
    int max_left[maxn];
    int max_right[maxn];

    memset(max_left, 0, sizeof(max_left));
    memset(max_right, 0, sizeof(max_right));

    for (int i = 1; i <= n; i++) {
        max_left[i] = max(max_left[i - 1], start[i]);
    }

    for (int i = (n - k) + 1; i > 0; i--) {
        max_right[i] = max(max_right[i + 1], start[i]);
    }

    // iterate over midline and keep track of best possible sum
    int best = 0;

    for (int i = 1; i <= (n - k + 1); i++) {
        cout << max_left[i] << " " << max_right[i + k] << endl;
        best = max(best, max_left[i] + max_right[i + k]);
    }

    cout << best << endl;

    return 0;
}