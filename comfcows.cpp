#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e3;

using pi = pair<int, int>;

bool added[maxn][maxn];

int ans = 0;

void addpt(int x, int y);
void checknb(int x, int y);
void fixpt(int x, int y);

void addpt(int x, int y) {
    // check if already added
    if(added[x][y]) return;

    added[x][y] = true;
    ans++;

    // when u add a cow two things can happen
    fixpt(x, y);
    checknb(x, y);
}

void checknb(int x, int y) {
    pi nb[4] = {{x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}};
    for (int i = 0; i < 4; i++) {
        if(added[nb[i].first][nb[i].second]) fixpt(nb[i].first, nb[i].second);
    }
}

void fixpt(int x, int y) {
    // fixing a point is equivalent to adding a cow where needed
    pi nb[4] = {{x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}};
    int sum = 0;
    pi need_to_fix;
    for (int i = 0; i < 4; i++) {
        int curr = added[nb[i].first][nb[i].second];
        if (curr == 0) need_to_fix = nb[i];
        sum += curr;
    }

    if(sum == 3) {
        addpt(need_to_fix.first, need_to_fix.second);
    }
}

int main() {
    int n;
    cin >> n;

    memset(added, false, sizeof(added));

    for(int i = 0; i < n; i++) {
        pi pt;
        cin >> pt.first >> pt.second;
        pt.first += maxn / 2;
        pt.second += maxn / 2;
        
        addpt(pt.first, pt.second);

        cout << ans - i - 1 << endl;
    }

    return 0;
}