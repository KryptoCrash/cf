#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
using ll = long long;
using vi = vector<int>;

struct DSU {
    vi par;
    vi sz;
    void init(int n) {
        for (int i = 0; i < n; i++) {
            par.push_back(i);
            sz.push_back(1);
        }
    }
    int get_rep(int node) {
        if (par[node] == node) return node;
        return get_rep(par[node]);
    }
    bool check_con(int a, int b) {
        return get_rep(a) == get_rep(b);
    }
    void unite(int a, int b) {
        int x = get_rep(a);
        int y = get_rep(b);
        if (x == y) return;
        if (sz[x] < sz[y]) {
            par[x] = y;
            sz[y] += sz[x];
        } else {
            par[y] = x;
            sz[x] += sz[y];
        }
    }
};

int main(int argc, char const *argv[]) {
    ifstream fin("milkvisits.in");
    ofstream fout("milkvisits.out");

    int n, m;
    fin >> n >> m;

    char fc[maxn];
    for (int i = 0; i < n; i++) {
        fin >> fc[i];
    }

    DSU ed;
    ed.init(n);

    // Unite if same color
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        fin >> x >> y;
        x--, y--;

        if (fc[x] == fc[y]) ed.unite(x, y);
    }

    // Check if same comp or still works
    for (int i = 0; i < m; i++) {
        int x, y;
        char c;
        fin >> x >> y >> c;
        x--, y--;

        fout << (!ed.check_con(x, y) || fc[x] == c);
    }

    fout << endl;

    return 0;
}