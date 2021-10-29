#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 8;
const int INF = 0x3f3f3f3f;

/*
dfs to get dist to start and dist to nearest end

recurse on subtrees
check if you can get to current root node (dist to start < dist to nearest end)
if you can, recurse on subtrees
if you cant add ans by 1
*/

int dist_to_start[maxn];
int dist_to_end[maxn];
int n, k;
set<int> ed[maxn];
int ans = 0;

int dfs(int node, int depth) {
    dist_to_start[node] = depth;
    int near_end = INF;
    for (int child : ed[node]) {
        near_end = min(near_end, dfs(child, depth + 1));
    }

    dist_to_end[node] = ed[node].size() < 1 ? 0 : near_end + 1;

    return dist_to_end[node];
}

void removePar(int node, int par) {
    if(par != -1) ed[node].erase(par);
    for (int child : ed[node]) {
        removePar(child, node);
    }
}

void acc(int node) {
    if(dist_to_start[node] >= dist_to_end[node]) ans++;
    else {
        for(int child : ed[node]) {
            acc(child);
        }
    }
}

int main() {
    ifstream fin("atlarge.in");
    ofstream fout("atlarge.out");

    fin >> n >> k;
    k--;

    memset(dist_to_start, 0, sizeof(dist_to_start));
    memset(dist_to_end, 0, sizeof(dist_to_end));

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        fin >> x >> y;
        x--, y--;

        ed[x].insert(y);
        ed[y].insert(x);
    }

    removePar(k, -1);

    dfs(k, 0);

    acc(k);

    fout << ans << endl;

    return 0;
}