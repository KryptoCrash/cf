#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e4 + 8;

int sz[maxn];
int psum[maxn];
int ssum[maxn];

bool ok(int i, int mid, int k) {
    return abs(mid - i) <= k;
}

int main(int argc, char const* argv[]) {
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");

    int n, k;
    fin >> n >> k;

    for (int i = 0; i < n; i++) {
        fin >> sz[i];
    }

    sort(sz, sz + n);

    // prefix sum (max size up to i)
    memset(psum, 0, sizeof(psum));
    psum[0] = 1;
    for (int i = 1; i < n; i++) {
        int lo = 0;
        int hi = i;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (ok(sz[i], sz[mid], k)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        psum[i] = max(psum[i - 1], i - lo + 1);
    }

    // suffix sum (max size after i)
    memset(ssum, 0, sizeof(ssum));
    ssum[n] = 0;
    ssum[n - 1] = 1;

    for (int i = n - 1; i >= 0; i--) {
        int lo = i;
        int hi = n - 1;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (ok(sz[i], sz[mid], k)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }

        ssum[i] = max(ssum[i + 1], lo - i + 1);
    }

    int mx_sz = 0;
    for (int i = 0; i < n; i++) {
        mx_sz = max(mx_sz, psum[i] + ssum[i + 1]);
    }

    fout << mx_sz << endl;

    return 0;
}
