#include <bits/stdc++.h>

using namespace std;

using pi = pair<int, int>;

const int maxn = 100 + 8;
const int maxm = 2e4 + 8;

int n, m;

set<pi> lights[maxn][maxn];

bool handled[maxn][maxn];
bool on[maxn][maxn];
bool visited[maxn][maxn];
int lights_on = 1;
bool all_handled = false;

void f_fill(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) return;
    if (visited[x][y]) return;
    if (!on[x][y]) return;

    visited[x][y] = true;

    if (!handled[x][y]) {
        all_handled = false;
        handled[x][y] = true;

        for (pi l : lights[x][y]) {
            if (!on[l.first][l.second]) {
                on[l.first][l.second] = true;
                lights_on++;
            }
        }
    }

    f_fill(x + 1, y);
    f_fill(x - 1, y);
    f_fill(x, y + 1);
    f_fill(x, y - 1);
}

int main() {
    ifstream fin("lightson.in");
    ofstream fout("lightson.out");

    fin >> n >> m;

    memset(handled, false, sizeof(handled));
    memset(on, false, sizeof(on));

    for (int i = 0; i < m; i++) {
        int x, y, a, b;
        fin >> x >> y >> a >> b;
        x--, y--, a--, b--;

        lights[x][y].insert({a, b});
    }

    on[0][0] = true;

    while (!all_handled) {
        all_handled = true;
        memset(visited, false, sizeof(visited));
        f_fill(0, 0);
    }

    fout << lights_on << endl;

    return 0;
}