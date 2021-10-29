#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int all = pow(m, n);
    int no = n - k + 1;

    cout << all - no << endl;

    return 0;
}