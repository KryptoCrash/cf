#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

const ll ALPHABET_SIZE = 3;
const ll mod = 1e9 + 7;

// trie node
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void) {
    struct TrieNode *pNode = new TrieNode;

    pNode->isEndOfWord = false;

    for (ll i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

// If not present, inserts key llo trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key) {
    struct TrieNode *pCrawl = root;

    for (ll i = 0; i < key.length(); i++) {
        ll index = key[i] - '0';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else
// false
bool search(struct TrieNode *root, string key) {
    struct TrieNode *pCrawl = root;

    for (ll i = 0; i < key.length(); i++) {
        ll index = key[i] - '0';
        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl->isEndOfWord);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    ll p;
    cin >> p;

    vi a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<string> bits(n);

    for (ll i = 0; i < n; i++) {
        string s;
        bool found = false;
        bool last0 = false;
        for (ll b = 35; b >= 0; b--) {
            if ((1LL << b) & a[i]) {
                s += '1';
                found = true;
                last0 = false;
            } else if (found && !last0) {
                s += '0';
                last0 = true;
            } else if (found && last0) {
                s.pop_back();
                s += '2';
                last0 = false;
            }
        }

        bits[i] = s;
    }

    for (int i = 0; i < n; i++) {
        ll lst = -1;
        for (int j = 1; j < bits[i].length(); j++) {
            if (bits[i][j - 1] == '1' && bits[i][j] == '2') {
                lst = j;
            }
            if (bits[i][j - 1] == '1' && bits[i][j] == '0') lst = -1;
            if (bits[i][j] == '0' && lst != -1) {
                bits[i][lst] = '0';
                bits[i][j] = '2';
            }
        }
    }

    struct TrieNode *root = getNode();

    for (ll i = 0; i < n; i++)
        insert(root, bits[i]);

    vi reachable(2e5 + 8);
    reachable[0] = 1;
    reachable[1] = 1;
    for (int i = 2; i < 2e5 + 8; i++) {
        reachable[i] += reachable[i - 1] + reachable[i - 2];
        reachable[i] %= mod;
    }

    vi psum(2e5 + 9);

    for (int i = 0; i < 2e5 + 8; i++) {
        psum[i + 1] = psum[i] + reachable[i];
        psum[i + 1] %= mod;
    }

    ll tot = 0;
    function<ll(TrieNode *, ll, ll)> dfs = [&](TrieNode *v, ll val, ll len) {
        ll cursum = 0;
        for (ll i = 0; i < 3; i++) {
            if (!v->children[i]) continue;

            ll va = dfs(v->children[i], i, len + (i == 2 ? 2 : 1));

            cursum += va % mod;
            cursum %= mod;
        }

        ll reach = 0;
        if (v->isEndOfWord && len > 0) {
            reach += (p - len < 0 ? 0 : psum[p - len + 1]);
            reach %= mod;

            reach -= cursum;
            reach %= mod;
            tot += reach;
            tot %= mod;
        }

        if (val == 0) return 0LL;

        return (reach + cursum) % mod;
    };

    dfs(root, -1, 0);
    tot %= mod;
    if (tot < 0) tot += mod;
    tot %= mod;
    cout << tot << endl;

    return 0;
}