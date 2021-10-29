#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;
using ti = array<int, 3>;
const int maxn = 1e5 + 8;

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

int main() {
    ifstream fin("mootube.in");
    ofstream fout("mootube.out");

    int n, q;
    fin >> n >> q;
    ti ed[maxn];

    DSU con;
    con.init(n);

    for (int i = 0; i < n - 1; i++) {
        fin >> ed[i][1] >> ed[i][2] >> ed[i][0];
        ed[i][0]--, ed[i][1]--, ed[i][2]--;
    }

    sort(ed, ed + n - 1, greater<ti>());

    ti qu[maxn];

    for (int i = 0; i < q; i++) {
        fin >> qu[i][0] >> qu[i][1];
        qu[i][0]--, qu[i][1]--;
        qu[i][2] = i;
    }

    sort(qu, qu + q, greater<ti>());

    int ans[maxn];

    int last_e = 0;
    for (int i = 0; i < q; i++) {
        int curr_k = qu[i][0];
        while (ed[last_e][0] >= curr_k && last_e < n - 1) {
            ti curr_e = ed[last_e];
            con.unite(curr_e[1], curr_e[2]);

            last_e++;
        }
        ans[qu[i][2]] = con.sz[con.get_rep(qu[i][1])] - 1;
    }

    for (int i = 0; i < q; i++) {
        fout << ans[i] << endl;
    }

    return 0;
}
