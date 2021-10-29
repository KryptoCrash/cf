#include <bits/stdc++.h>

using namespace std;

string solve() {
    string buf;
    cin >> ws;
    getline(cin, buf);

    for (int i = 0; i < buf.size(); i++) {
        char c = buf[i];

        if(i % 2 == 0) {
            buf[i] = (c == 'a' ? 'b' : 'a');
        } else {
            buf[i] = (c == 'z' ? 'y' : 'z');
        }
    }

    return buf;
}

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;

    while(t--) {
        cout << solve() << endl;
    }

    return 0;
}