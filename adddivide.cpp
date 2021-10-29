#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9+8;

int solve() {
    int a, b;
    cin >> a >> b;

    if(a == 0) return 0;

    int x = b;
    int best = INF;
    while(true) {
        if(x == 1 || x == 0) {
            x++;
            continue;
        }
        int div = 0;
        int cu = a;
        while(cu > 0) {
            cu /= x;
            div++;
        }
        
        if(div < best) {
            best = div;
            x++;
        } else {
            x--;
            break;
        };
    }
    return x - b + best;
}

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;

    while(t--) cout << solve() << endl;

    return 0;
}