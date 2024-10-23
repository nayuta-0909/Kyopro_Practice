#include <iostream>  // 標準入出力用のライブラリ
#include <queue>     // キューを使うためのライブラリ

using namespace std;

static const int N = 100;  // 頂点の最大数を100に設定
static const int INFTY = (1 << 21);  // 無限大に相当する値を設定（2の21乗）

int n, M[N][N];  // n: 頂点数、M: 隣接行列（頂点間の接続を示す）
int d[N];  // d: 各頂点までの距離を格納する配列（訪問状態も管理）

// 幅優先探索 (BFS) を行う関数
void bfs(int s) {
    queue<int> q;  // 幅優先探索で使用するキュー
    q.push(s);  // スタート頂点sをキューに追加
    
    // 全ての頂点の距離を無限大に初期化
    for (int i = 0; i < n; i++) d[i] = INFTY;
    d[s] = 0;  // スタート頂点の距離は0に設定

    int u;
    while (!q.empty()) {  // キューが空になるまでループ
        u = q.front();  // キューの先頭の頂点を取得
        q.pop();  // キューから削除

        // 隣接する頂点vに対する処理
        for (int v = 0; v < n; v++) {
            if (M[u][v] == 0) continue;  // 隣接していない場合はスキップ
            if (d[v] != INFTY) continue;  // 既に訪問済みならスキップ
            d[v] = d[u] + 1;  // 距離を更新
            q.push(v);  // 次の探索対象としてvをキューに追加
        }
    }

    // 結果を出力
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " " << ((d[i] == INFTY) ? -1 : d[i]) << endl;  // 頂点番号と距離を出力
    }
}

int main() {
    int u, k, v;

    cin >> n;  // 頂点数nを入力
    // 隣接行列を初期化（すべての辺を0に設定）
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) M[i][j] = 0;
    }

    // 各頂点に対する隣接情報を入力
    for (int i = 0; i < n; i++) {
        cin >> u >> k;  // 頂点uとその隣接頂点の数kを入力
        u--;  // 頂点番号を0始まりに変換
        for (int j = 0; j < k; j++) {
            cin >> v;  // 隣接する頂点vを入力
            v--;  // 頂点番号を0始まりに変換
            M[u][v] = 1;  // 隣接行列に辺が存在することを反映
        }
    }

    bfs(0);  // 0番目の頂点から幅優先探索を開始

    return 0;
}
