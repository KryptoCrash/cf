#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
using vi = vector<int>;

vi s_n[maxn];
vi d_n[maxn];
int nodes[maxn];
bool imp = false;

// DFS to see if things work
void dfs(int node, int par) {
    if (par == -1) nodes[node] = 0;
    int col = nodes[node];
    for (int sn : s_n[node]) {
        if (nodes[sn] == -1) {
            nodes[sn] = col;
            dfs(sn, node);
        }
        else if (nodes[sn] != col)
            imp = true;
    }
    for (int dn : d_n[node]) {
        if (nodes[dn] == -1) {
            nodes[dn] = col ^ 1;
            dfs(dn, node);
        } else if (nodes[dn] == col)
            imp = true;
    }
}

int main(int argc, char const *argv[]) {
    ifstream fin("revegetate.in");
    ofstream fout("revegetate.out");

    int n, m;
    fin >> n >> m;

    memset(nodes, -1, sizeof(nodes));

    for (int i = 0; i < m; i++) {
        char c;
        int x, y;

        fin >> c >> x >> y;
        x--, y--;

        if (c == 'S') {
            s_n[x].push_back(y);
            s_n[y].push_back(x);
        } else {
            d_n[x].push_back(y);
            d_n[y].push_back(x);
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (nodes[i] > -1) continue;
        sum++;
        dfs(i, -1);
    }

    if (imp)
        fout << "0";
    else {
        fout << "1";
        for (int i = 0; i < sum; i++) {
            fout << "0";
        }
        fout << endl;
    }

    return 0;
}
