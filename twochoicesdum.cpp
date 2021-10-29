#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 8;

int BitCount(unsigned int u) {
    unsigned int uCount;

    uCount = u - ((u >> 1) & 033333333333) - ((u >> 2) & 011111111111);
    return ((uCount + (uCount >> 3)) & 030707070707) % 63;
}

int main() {
    int n, m;
    cin >> n >> m;

    int choices[maxn];

    for (int i = 0; i < n; i++) {
        string curr;
        cin >> ws;
        getline(cin, curr);
        choices[i] = stoi(curr, nullptr, 2);
    }

    int sum = 0;

    for (int a = 0; a < n; a++) {
        for (int b = a + 1; b < n; b++) {
            int val = choices[a] ^ choices[b];
            sum += BitCount(val) % 2 == 0 ? 0 : 1;
        }
    }

    cout << sum << endl;

    return 0;
}