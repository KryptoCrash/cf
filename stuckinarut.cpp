#include <bits/stdc++.h>

using namespace std;

using pi = array<int, 3>;
using vpi = vector<pi>;
const int maxn = 1000 + 8;

bool ycmp(pi a, pi b) { return a[1] < b[1]; }

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;

    vpi north, east;
    bool removed[maxn]{false};
    int stop[maxn]{0};

    for (int i = 0; i < n; i++) {
        char c;
        int x, y;
        cin >> c >> x >> y;
        if(c == 'N') {
            north.push_back({x, y, i});
        } else {
            east.push_back({x, y, i});
        }
    }

    sort(north.begin(), north.end());
    sort(east.begin(), east.end(), ycmp);

    for(pi nc : north) {
        for(pi ec : east) {
            if(removed[ec[2]]) continue;
            if(ec[1] < nc[1] || ec[0] > nc[0]) continue;
            int ec_dist = nc[0] - ec[0];
            int nc_dist = ec[1] - nc[1];
            if(nc_dist == ec_dist) continue;
            if(ec_dist < nc_dist) {
                stop[ec[2]] += stop[nc[2]] + 1;
                break;
            }
            if(nc_dist < ec_dist) {
                stop[nc[2]] += stop[ec[2]] + 1;
                removed[ec[2]] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << stop[i] << endl;
    }

    return 0;
}