#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 8;

int main() {
    ifstream fin("haybales.in");
    ofstream fout("haybales.out");

    int n, q;
    fin >> n >> q;

    int h[maxn];

    for (int i = 0; i < n; i++) {
        fin >> h[i];
    }

    sort(h, h + n);

    for (int i = 0; i < q; i++) {
        int a, b;
        fin >> a >> b;

        // bin search for a
        int lo = 0;
        int hi = n - 1;

        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (h[mid] >= a) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        int a_i = hi;

        // bin search for b
        lo = 0;
        hi = n - 1;

        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (h[mid] <= b) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }

        int b_i = lo;

        int ans = b_i - a_i;
        if (b >= h[0] && a <= h[n - 1]) ans++;

        fout << ans << endl;
    }
}