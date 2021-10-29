#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 8;
using ll = long long;
using pi = pair<int, int>;

ll psum[maxn][maxn];

// INCLUSIVE
int get_sum(int ax, int ay, int bx, int by) {
    return psum[bx][by] - psum[ax][by] - psum[bx][ay] + psum[ax][ay];
}

bool ycmp(pi a, pi b) { return a.second < b.second; }

int main(int argc, char const *argv[]) {
    ifstream fin("balancing.in");
    ofstream fout("balancing.out");

    int n;
    fin >> n;

    pi p[maxn];
    for (int i = 1; i <= n; i++) {
        fin >> p[i].first >> p[i].second;
    }

    sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; i++) {
        p[i].first = i;
    }

    sort(p + 1, p + n + 1, ycmp);
    for (int i = 1; i <= n; i++) p[i].second = i;

    // construct psum
    memset(psum, 0, sizeof(psum));

    for (int i = 1; i <= n; i++) {
        psum[p[i].first][p[i].second] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            psum[i][j] += psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
        }
    }

    int best = 0x3f3f3f3f;

    // Use all possible pairs of numbers
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            int q1 = get_sum(0, 0, a, b);
            int q2 = get_sum(0, a, b, n);
            int q3 = get_sum(b, 0, n, a);
            int q4 = get_sum(a, b, n, n);

            int mx = max({q1, q2, q3, q4});

            best = min(best, mx);
        }
    }

    fout << best << endl;

    return 0;
}