#include <bits/stdc++.h>

using namespace std;

using pi = pair<int, int>;

const int maxn = 2e5;

int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;

    int a[maxn];
    pi man[maxn];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> man[i].first >> man[i].second;
    }

    // Precompute

    stack<pi> sorts;
    pi mx = {0, 0};

    for (int i = m - 1; i >= 0; i--) {
        // check if max
        if(man[i].second > mx.second) {
            mx = man[i];
            sorts.push(mx);
        }
    }

    pi big_sort = sorts.top();
    sorts.pop();

    int last_sort_type = big_sort.first;
    int last_sort_i = big_sort.second;
    int l = 0; int r = big_sort.second - 1;

    sort(a, a + r + 1);

    int ans[maxn];
    for (int i = 0; i < n; i++) {
        ans[i] = a[i];
    }
    int curr_i = r;

    while(!sorts.empty()) {
        pi srt = sorts.top();
        sorts.pop();

        int sort_type = srt.first;
        if(sort_type == last_sort_type) continue;
        last_sort_type = sort_type;

        int sort_i = srt.second;
        int sort_diff = last_sort_i - sort_i;
        // Start from L
        if(sort_type == 1) {
            for (int i = l; i < l + sort_diff; i++) {
                ans[curr_i--] = a[i];
            }
            l += sort_diff;
        }
        // Start from R
        else {
            for (int i = r; i > r - sort_diff; i--) {
                ans[curr_i--] = a[i];
            }
            r -= sort_diff;
        }

        last_sort_i = sort_i;
    }

    if(last_sort_type == 1) {
        for (int i = r; i >= l; i--) {
            ans[curr_i--] = a[i];
        }
    } else {
        for (int i = l; i <= r; i++) {
            ans[curr_i--] = a[i];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}