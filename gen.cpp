#include <bits/stdc++.h>
using namespace std;
int rnd(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char *argv[]) {
    srand(time(NULL) + stoi(argv[1]));

    int n = rnd(1, 1e5);
    bool usingdup = rnd(1, 20) == 1;
    int m = rnd(1, (usingdup ? 1e5 : (int)(1.2 * n)));
    cout << n << " " << m << endl;

    vector<int> cnt(n+1, 2);

    for (int i = 0; i < m; i++) {
        int v;
	v = rnd(1, n);
        while (cnt[v] == 0 && !usingdup) {
		v = rnd(1, n);
        }
	cnt[v]--;
        cout << v << (i == m - 1 ? "" : " ");
    }
    cout << endl;
}
