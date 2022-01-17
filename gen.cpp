#include <bits/stdc++.h>
using namespace std;
int rnd(int a, int b) {
    return a + rand() % (b - a + 1);
}
int main() {
    srand(time(NULL));

    int n = rnd(1, 10);

    cout << n << endl;

    int lst = 2;
    set<int> ys;
    for (int i = 0; i < n; i++) {
        int x = rnd(lst, 1e3 + lst);

        int y = rnd(1, x - 1);
        while (ys.find(y) != ys.end()) y = rnd(1, x - 1);

        lst = x + 1;

        cout << x << " " << y << " " << rnd(0, 1) << endl;
    }
}