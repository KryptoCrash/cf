#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

ll n, m;

vector<vector<bool>> a;
vector<vector<bool>> visited;

void f_fill(ll x, ll y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return;
    if (visited[x][y]) return;
    if (a[x][y]) return;

    visited[x][y] = true;

    f_fill(x + 1, y);
    f_fill(x - 1, y);
    f_fill(x, y + 1);
    f_fill(x, y - 1);
}

int main() {
    cin >> n >> m;

    a = vector<vector<bool>>(n, vector<bool>(m, 0));
    visited = vector<vector<bool>>(n, vector<bool>(m, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c;
            cin >> c;

            if (c == '#') a[i][j] = true;
        }
    }
    int sum = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (!visited[i][j] && !a[i][j]) {
                sum++;
                f_fill(i, j);
            }
        }
    }

    cout << sum << endl;

    return 0;
}