//深さ優先探索

#include <stdio.h>
#define N 100        // ノードの最大数を100と定義
#define WHITE 0      // WHITE: 未訪問ノード
#define GRAY 1       // GRAY: 訪問中のノード
#define BLACK 2      // BLACK: 訪問済みノード

int n, M[N][N];      // nはノード数、Mは隣接行列 (グラフの接続関係を格納)
int color[N], d[N], f[N], tt; // colorはノードの訪問状態、dは訪問開始時間、fは訪問終了時間、ttはタイムスタンプ

// 深さ優先探索 (DFS) の各ノードに対する再帰処理
void dfs_visit(int u) {
    int v;
    color[u] = GRAY;
    d[u] = ++tt;
    for(v=0; v<n;v++) {
        if(M[u][v] == 0) continue;
        if( color[v] == WHITE){
            dfs_visit(v);
        }
    }
    color[u] = BLACK;
    f[u] = ++tt;
}

// グラフ全体に対してDFSを実行
void dfs() {
    for (int u = 0; u < n; u++) color[u] = WHITE; // 全てのノードを未訪問 (WHITE) に初期化
    tt = 0; // タイムスタンプを0に初期化
    for (int u = 0; u < n; u++) { // 各ノードに対してDFSを開始
        if (color[u] == WHITE) dfs_visit(u); // 未訪問のノードがあればDFSを実行
    }
    for (int u = 0; u < n; u++) {
        printf("%d %d %d\n", u + 1, d[u], f[u]); // 各ノードの訪問開始時間と完了時間を出力
    }
}

int main() {
    int u, v, k, i, j;

    // ノード数を入力
    scanf("%d", &n);
    // 隣接行列を初期化 (全ての要素を0に設定)
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) M[i][j] = 0;
    }

    // グラフの隣接行列を構築
    for (i = 0; i < n; i++) {
        scanf("%d %d", &u, &k); // ノード u と隣接ノードの数 k を入力
        u--; // 入力を0インデックスに変換
        for (j = 0; j < k; j++) {
            scanf("%d", &v); // 隣接ノード v を入力
            v--; // 入力を0インデックスに変換
            M[u][v] = 1; // ノード u と v の間に辺があることを隣接行列に記録
        }
    }

    dfs(); // グラフに対してDFSを実行
    return 0;
}
