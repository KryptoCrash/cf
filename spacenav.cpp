#include <bits/stdc++.h>

using namespace std;

bool solve() {
    int x, y, temp;
    cin >> x >> y;

    int numdir[4]{0};
    pair<int, int> pos = {0, 0};

    string buff;
    cin >> ws;
    getline(cin, buff);

    for (char c : buff) {
        if (c == 'U') {
            numdir[0]++;
            pos.second++;
        }
        if (c == 'D') {
            numdir[1]++;
            pos.second--;
        }
        if (c == 'R') {
            numdir[2]++;
            pos.first++;
        }
        if (c == 'L') {
            numdir[3]++;
            pos.first--;
        }
    }

    int xdiff = x - pos.first;
    int ydiff = y - pos.second;

    bool ok = true;
    if (xdiff > 0) {
        ok = xdiff <= numdir[3];
    }
    if(xdiff < 0) {
        ok = -xdiff <= numdir[2];
    }

    if (ok == false) return ok;

    if (ydiff > 0) {
        ok = ydiff <= numdir[1];
    }
    if (ydiff < 0) {
        ok = -ydiff <= numdir[0];
    }

    return ok;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cout << (solve() ? "YES" : "NO") << endl;
    }

    return 0;
}