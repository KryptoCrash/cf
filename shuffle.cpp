#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 8;
using pi = pair<int, int>;

bool visited[maxn];
int a[maxn];
int tot = 0;

pi dfs(int node, int depth) {
    if (visited[node]) return {node, depth};
    visited[node] = true;
    pi cycle_end = dfs(a[node], depth + 1);
    if(cycle_end.first == node) {
        tot += cycle_end.second - depth;
    }
    return cycle_end;
}

int main() {
    ifstream fin("shuffle.in");
    ofstream fout("shuffle.out");

    int n;
    fin >> n;

    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++) {
        fin >> a[i];
        a[i]--;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs(i, 0);
    }

    fout << tot << endl;

    return 0;
}