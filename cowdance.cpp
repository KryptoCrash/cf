#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4;

int n, t;
int d[maxn];

bool ok(int k) {
    priority_queue<int, vector<int>, greater<int>> ends;
    int mx_time = 0;
    for (int i = 0; i < k; i++) {
        mx_time = max(d[i], mx_time);
        ends.push(d[i]);
    }

    int nxt = k;

    while (!ends.empty()) {
        int done = ends.top();
        ends.pop();

        if (nxt < n) {
            ends.push(d[nxt] + done);
            mx_time = max(d[nxt] + done, mx_time);
        }
        nxt++;
    }

    return mx_time <= t;
}

int main() {
    ifstream fin("cowdance.in");
    ofstream fout("cowdance.out");

    fin >> n >> t;

    for (int i = 0; i < n; i++) {
        fin >> d[i];
    }

    // bin search on answer
    int lo = 1;
    int hi = n;

    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (ok(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    fout << hi << endl;
}