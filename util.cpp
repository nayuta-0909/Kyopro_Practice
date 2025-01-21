#include<iostream> // 標準入力・出力を扱うライブラリ
using namespace std; // 標準ライブラリの名前空間を使う

static const int MAX = 100; // 最大ノード数
static const int INFTY = (1<<21); // 無限大（大きな数）
static const int WHITE = 0; // 未訪問ノード
static const int GRAY = 1; // 訪問中のノード
static const int BLACK = 2; // 訪問完了ノード

int n, M[MAX][MAX]; // ノード数nと隣接行列M

int prim() {
    int u, minv;
    int d[MAX], p[MAX], color[MAX];

    for(int i=0;i<n;i++) {
        d[i] = INFTY;
        p[i] = -1;
        color[i] = WHITE;
    }

    d[0] =0;
    while(1) {
        minv=INFTY;
        u=-1;

        for(int i=0;i<n;i++) {
            if (minv > d[i] && color[i] != BLACK) {
                u = i;
                minv = d[i];
            }
        }
    }
}