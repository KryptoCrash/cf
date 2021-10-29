#include <bits/stdc++.h>

using namespace std;

const int maxn = 104;

int n, k;
bool visited[maxn][10];
int board[maxn][10];
int region[maxn][10];
int regsize[maxn * 10]{0};
int c_reg = 1;
int c_size = 0;
int c_col = 0;

void f_fill(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= 10) return;
    if(visited[x][y]) return;
    if(board[x][y] != c_col) return;

    visited[x][y] = true;
    region[x][y] = c_reg;
    c_size++;

    f_fill(x + 1, y);
    f_fill(x - 1, y);
    f_fill(x, y + 1);
    f_fill(x, y - 1);
}

int main(int argc, char const *argv[]) {
    ifstream fin("mooyomooyo.in");
    ofstream fout("mooyomooyo.out");

    fin >> n >> k;

    char curr_c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            fin >> curr_c;
            board[i][j] = curr_c - '0';
        }
    }

    while(true) {
        memset(visited, false, sizeof(visited));
        memset(region, 0, sizeof(region));
        memset(regsize, 0, sizeof(regsize));
        c_reg = 1;
        c_size = 0;
        c_col = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                if(visited[i][j]) continue;

                c_size = 0;
                c_col = board[i][j];
                if(c_col == 0) continue;
                f_fill(i, j);

                regsize[c_reg] = c_size;
                c_reg++;
            }
        }

        bool size_found = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                int reg = region[i][j];

                if(regsize[reg] >= k) {
                    board[i][j] = 0;
                    size_found = true;
                }
            }
        }

        for (int j = 0; j < 10; j++) {
            int no_zero[maxn]{0};
            int no_zero_ind = n - 1;

            for (int i = n - 1; i >= 0; i--) {
                if(board[i][j] != 0) {
                    no_zero[no_zero_ind--] = board[i][j];
                }
            }

            for (int i = 0; i < n; i++) {
                board[i][j] = no_zero[i];
            }
        }

        if(!size_found) {
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            fout << board[i][j];
        }

        fout << endl;
    }

    return 0;
}