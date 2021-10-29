#include <bits/stdc++.h>
using namespace std;

const int maxn = 400 + 8;

template <class T>
struct Seg {  // comb(ID,b) = b
    const T ID = 0;
    T comb(T a, T b) { return max(a, b); }
    int n;
    vector<T> seg;
    void init(int _n) {
        n = _n;
        seg.assign(2 * n, ID);
    }
    void pull(int p) { seg[p] = comb(seg[2 * p], seg[2 * p + 1]); }
    void upd(int p, T val) {  // set val at position p
        seg[p += n] = val;
        for (p /= 2; p; p /= 2) pull(p);
    }
    T query(int l, int r) {  // min on interval [l, r]
        T ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) ra = comb(ra, seg[l++]);
            if (r & 1) rb = comb(seg[--r], rb);
        }
        return comb(ra, rb);
    }
};

Seg<int> mxs;
int psum[maxn];

int calc_seg_cost(int i, int j) {
    return (j - i) * mxs.query(i + 1, j) - (psum[j] - psum[i]);
}

int main(int argc, char const *argv[]) {
    ifstream fin("snakes.in");
    ofstream fout("snakes.out");

    int n, k;
    fin >> n >> k;
    k++;

    mxs.init(n + 1);

    memset(psum, 0, sizeof(psum));

    psum[0] = 0;

    for (int i = 1; i <= n; i++) {
        int a;
        fin >> a;
        mxs.upd(i, a);
        psum[i] = psum[i - 1] + a;
    }

    // DP: (i, k)
    int dp[maxn][maxn];

    fill_n(&dp[0][0], maxn * maxn, 0x3f3f3f3f);

    dp[0][k] = 0;

    for (int i = 0; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int cost = calc_seg_cost(i, j);

            for (int l = 1; l <= k; l++) {
                dp[j][l - 1] = min(dp[j][l - 1], dp[i][l] + cost);
            }
        }
    }

    fout << dp[n][0] << endl;

    return 0;
}