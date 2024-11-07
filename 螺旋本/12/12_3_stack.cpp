//深さ優先探索

#include <iostream>   
#include <stack>      
using namespace std;

static const int N = 100;   // グラフの最大頂点数Nを100に設定
static const int WHITE = 0; // 頂点が「未訪問」であることを示す定数
static const int GRAY = 1;  // 頂点が「訪問中」であることを示す定数
static const int BLACK = 2; // 頂点が「訪問完了」であることを示す定数

int n, M[N][N];    // n: 頂点数, M: 隣接行列（頂点間の接続関係を表す）
int color[N], d[N], f[N], tt; // color: 頂点の訪問状態, d: 発見時刻, f: 完了時刻, tt: 時刻カウンタ
int nt[N];         // nt: 次に探索する隣接頂点のインデックス

// 頂点uに隣接するvを番号順に取得する関数
//u:頂点
int next(int u) {
    for (int v = nt[u]; v < n; v++) {  // uの隣接頂点vを順番に探索
        nt[u] = v + 1;  // 次の探索対象インデックスを更新(処理時間を節約する)
        if (M[u][v]) return v;  // 隣接している頂点が見つかれば、その頂点を返す
    }
    return -1;  // 隣接する頂点がない場合は-1を返す
}

// スタックを用いた深さ優先探索
//r:頂点
void dfs_visit(int r) {
    for (int i = 0; i < n; i++) nt[i] = 0;  // 隣接頂点探索のためにnt配列を初期化

    stack<int> S;  // 深さ優先探索用のスタック
    S.push(r);     // 開始頂点rをスタックに追加
    color[r] = GRAY;  // 開始頂点を「訪問中」に設定
    d[r] = ++tt;      // 発見時刻を記録

    while (!S.empty()) {   // スタックが空でない限りループ
        int u = S.top();   // スタックの最上位の頂点uを取得
        int v = next(u);   // uの隣接頂点vを取得
        if (v != -1) {     // 隣接頂点が存在する場合
            if (color[v] == WHITE) {  // vが未訪問であれば
                color[v] = GRAY;      // vを「訪問中」に設定
                d[v] = ++tt;          // vの発見時刻を記録
                S.push(v);            // vをスタックに追加
            }
        } else {   // 隣接頂点が存在しない場合
            S.pop();       // 現在の頂点uをスタックから取り出す
            color[u] = BLACK;  // uを「訪問完了」に設定
            f[u] = ++tt;       // uの完了時刻を記録
        }
    }
}

// 深さ優先探索全体を実行する関数
void dfs() {
    // 初期化
    for (int i = 0; i < n; i++) {
        color[i] = WHITE;  // 全頂点を未訪問に設定
        nt[i] = 0;         // 次に探索する隣接頂点のインデックスを0に初期化
    }
    tt = 0;  // 時刻カウンタを0に初期化

    // 未訪問の頂点を始点として深さ優先探索を行う
    for (int u = 0; u < n; u++) {
        if (color[u] == WHITE) dfs_visit(u);  // 未訪問の頂点uから探索開始
    }

    // 各頂点の発見時刻と完了時刻を出力
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " " << d[i] << " " << f[i] << endl;  // 頂点番号、発見時刻、完了時刻を表示
    }
}

int main() {
    //u:頂点
    //k:頂点uの隣接頂点の数
    //v:隣接する頂点
    int u, k, v;

    cin >> n;  // 頂点数nを入力
    // 隣接行列Mを初期化（すべての頂点間の接続を0に設定）
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) M[i][j] = 0;
    }

    // グラフの隣接関係を入力
    for (int i = 0; i < n; i++) {
        cin >> u >> k;  // 頂点uとその隣接頂点の数kを入力
        u--;  // 頂点番号を0始まりにする
        for (int j = 0; j < k; j++) {
            cin >> v;   // 隣接する頂点vを入力
            v--;        // 頂点番号を0始まりにする
            M[u][v] = 1;  // 隣接行列Mで頂点uからvへの辺があることを示す
        }
    }

    dfs();  // 深さ優先探索を実行

    return 0;
}
