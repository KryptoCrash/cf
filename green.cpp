#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 500 + 8;
const int INF = 0x3f3f3f3f;

int main() {
    int n;
    cin >> n;

    int grid[maxn][maxn];
    int dist_to_nxt[maxn][maxn];
    int dist_to_nxt_any[maxn][maxn];

    memset(grid, 0, sizeof(grid));
    memset(dist_to_nxt, 0, sizeof(dist_to_nxt));
    memset(dist_to_nxt_any, 0, sizeof(dist_to_nxt_any));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Complementary counting (min >= 100 - min >= 101)
    for (int i = 0; i < n; i++) {
        int nxt_any = 0;
        int nxt = 0;
        for (int j = n - 1; j >= 0; j--) {
            nxt++, nxt_any++;
            if(grid[i][j] < 101) {
                nxt_any = 0;
                if(grid[i][j] < 100) {
                    nxt = 0;
                }
            }
            dist_to_nxt[i][j] = nxt;
            dist_to_nxt_any[i][j] = nxt_any;
        }
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // sum of indep values
            int min_dist = INF;
            int min_dist_any = INF;
            for (int k = i; k < n && !(grid[k][j] < 100); k++) {
                min_dist = min(min_dist, dist_to_nxt[k][j]);
                min_dist_any = min(min_dist_any, dist_to_nxt_any[k][j]);
                ans += min_dist - min_dist_any;
            }
        }
    }

    cout << ans << endl;

    return 0;
}