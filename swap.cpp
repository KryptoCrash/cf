#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;

int n, m, k;
int p[maxn];

int cl[maxn];
bool visited[maxn]{false};

int ans[maxn];

ifstream fin("swap.in");
ofstream fout("swap.out");

void dfs_cycles(int a, int b) {
    if(ans[a] >= 0) return;
    ans[a] = b;
    dfs_cycles(p[a], p[b]);
}

int get_cycle_length(int node, int depth) {
    if(visited[node]) return depth;
    visited[node] = true;
    cl[node] = get_cycle_length(p[node], depth + 1);
    return cl[node];
}

void simulate() {
    for (int i = 0; i < m; i++) {
        int l, r;
        fin >> l >> r;
        l--;

        reverse(p + l, p + r);
    }
}

int main(int argc, char const *argv[]) {
    fin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        p[i] = i;
    }

    simulate();

    for (int i = 0; i < n; i++) {
        get_cycle_length(i, 0);
    }

    memset(ans, -1, sizeof(ans));
    
    for (int i = 0; i < n; i++) {
        if(ans[i] >= 0) {
            fout << ans[i] + 1 << endl;
            continue;
        }

        int t_len = k % cl[i];
        int a = i;
        int b = a;
        for (int j = 0; j < t_len; j++) {
            b = p[b];
        }

        dfs_cycles(a, b);
        fout << ans[i] + 1 << endl;
    }

    return 0;
}