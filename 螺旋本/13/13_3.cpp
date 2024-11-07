#include<iostream> // 標準入力・出力を扱うライブラリ
using namespace std; // 標準ライブラリの名前空間を使用

static const int MAX = 100; // 最大ノード数
static const int INFTY = (1<<21); // 無限大（非常に大きな数）
static const int WHITE = 0; // 未訪問ノード
static const int GRAY = 1; // 訪問中のノード
static const int BLACK = 2; // 訪問完了ノード

int n, M[MAX][MAX]; // ノード数nと隣接行列M

// ダイクストラ法による単一始点最短経路を求める関数
void dijkstra() {
    int minv;
    int d[MAX], color[MAX]; // 各ノードの最短距離dとノードの状態を示すcolor

    //初期化
    for (int i = 0; i < n; i++) {
        d[i] = INFTY; // 最短距離を無限大に初期化
        color[i] = WHITE; // ノードの色を未訪問に初期化
    }

    d[0] = 0; // 始点の距離を0に設定
    color[0] = GRAY; // 始点を訪問中に設定

    while (1) {
        minv = INFTY;
        int u = -1;

        // 訪問中または未訪問の中から最小距離のノードを選ぶ
        for (int i = 0; i < n; i++) {
            if (minv > d[i] && color[i] != BLACK) {
                u = i;
                minv = d[i];
            }
        }

        if (u == -1) break; // 全てのノードを処理したら終了

        color[u] = BLACK; // ノードuを訪問完了に設定

        // 隣接するノードの距離を更新
        for (int v = 0; v < n; v++) {
            if (color[v] != BLACK && M[u][v] != INFTY) {
                if (d[v] > d[u] + M[u][v]) {
                    d[v] = d[u] + M[u][v]; // 距離を更新
                    color[v] = GRAY; // ノードvを訪問中に設定
                }
            }
        }
    }

    // 結果を出力
    for (int i = 0; i < n; i++) {
        cout << i << " " << ((d[i] == INFTY) ? -1 : d[i]) << endl; // ノードiの最短距離を表示
    }
}

int main() {
    cin >> n; // ノード数を入力

    // 隣接行列の入力
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int e;
            cin >> e;
            M[i][j] = (e == -1) ? INFTY : e; // -1は無効な辺として無限大に設定
        }
    }

    dijkstra(); // ダイクストラ法を実行
    return 0;
}
