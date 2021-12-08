#include <bits/stdc++.h>
using namespace std;
int rnd(int a, int b) {
    return a + rand() % (b - a + 1);
}
int main() {
    srand(time(NULL));

    int a = rnd(1, 10);
    int b = rnd(1, 10);
    cout << a << " " << b << endl;
}