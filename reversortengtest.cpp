#include <bits/stdc++.h>
using namespace std;

int main() {
    ofstream fout("reversorteng.in");
    srand(time(NULL));
    int t = 1000000;
    fout << t << endl;
    for (int i = 0; i < t; i++) {
        int n = rand() % 101;
        int c = rand() % 10001;
        fout << n << " " << c << endl;
    }
}