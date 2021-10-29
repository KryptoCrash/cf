#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream fout("fencepainting.in");
    srand(time(NULL));

    int t = rand() % 100;
    fout << t << endl;

    for (int i = 0; i < t; i++) {
        int n = rand() % 5 + 1;
        int m = rand() % 5 + 1;
        fout << n << " " << m << endl;

        for (int i = 0; i < n; i++) {
            fout << rand() % 5 << " ";
        }
        fout << endl;

        for (int i = 0; i < n; i++) {
            fout << rand() % 5 << " ";
        }
        fout << endl;

        for (int i = 0; i < m; i++) {
            fout << rand() % 5 << " ";
        }
        fout << endl;
    }

    return 0;
}