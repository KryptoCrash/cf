#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

vector<char> vowels = {'A', 'E', 'I', 'O', 'U'};

bool isVowel(char c) {
    return find(vowels.begin(), vowels.end(), c) != vowels.end();
}

void solve() {
    string s;
    cin >> s;

    char max_v;
    int max_v_cnt = 0;
    char max_c;
    int max_c_cnt = 0;

    int max_char[26];

    memset(max_char, 0, sizeof(max_char));

    for (char c : s) {
        max_char[c - 'A']++;
    }

    for (int i = 0; i < 26; i++) {
        // if vowel
        if (isVowel((char)(i + 'A'))) {
            if(max_char[i] > max_v_cnt) {
                max_v_cnt = max_char[i];
                max_v = (char)(i + 'A');
            }
        } else {
            if (max_char[i] > max_c_cnt) {
                max_c_cnt = max_char[i];
                max_c = (char)(i + 'A');
            }
        }
    }

    // sw to vowel
    int best_vowel = 0;
    for (char c : s) {
        if(isVowel(c)) {
            best_vowel += c == max_v ? 0 : 2;
        } else
            best_vowel++;
    }

    // sw to cons
    int best_cons = 0;
    for (char c : s) {
        if (!isVowel(c)) {
            best_cons += c == max_c ? 0 : 2;
        } else
            best_cons++;
    }

    cout << min(best_vowel, best_cons) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}