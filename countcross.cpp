#include <bits/stdc++.h>

using namespace std;

const int maxn = 100;
using pi = pair<int, int>;

int n, k, r;
map<pi, set<pi>> roads;
bool cow_at_loc[maxn][maxn];
pi cows[maxn];

bool visited[maxn][maxn];
int c_cows_found = 0;
void f_fill(int x, int y, int parx, int pary) {
    if (x < 0 || x >= n || y < 0 || y >= n) return;
    if (visited[x][y]) return;
    if (roads[{x, y}].find({parx, pary}) != roads[{x, y}].end()) return;

    visited[x][y] = true;
    if (cow_at_loc[x][y]) c_cows_found++;

    f_fill(x + 1, y, x, y);
    f_fill(x - 1, y, x, y);
    f_fill(x, y + 1, x, y);
    f_fill(x, y - 1, x, y);
}

int main(int argc, char const *argv[]) {
    ifstream fin("countcross.in");
    ofstream fout("countcross.out");

    fin >> n >> k >> r;

    for (int i = 0; i < r; i++) {
        pi a, b;
        fin >> a.first >> a.second >> b.first >> b.second;
        a.first--, a.second--, b.first--, b.second--;
        roads[a].insert(b);
        roads[b].insert(a);
    }

    for (int i = 0; i < k; i++) {
        fin >> cows[i].first >> cows[i].second;
        cows[i].first--, cows[i].second--;
        cow_at_loc[cows[i].first][cows[i].second] = true;
    }

    int sum = 0;

    for (int i = 0; i < k; i++) {
        memset(visited, false, sizeof(visited));
        c_cows_found = 0;
        f_fill(cows[i].first, cows[i].second, -1, -1);
        sum += k - c_cows_found;
    }

    fout << sum / 2 << endl;

    return 0;
}
