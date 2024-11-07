#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
static const int MAX = 10000; // ノードの最大数
static const int INFTY = (1<<20); // 無限大を表す値（十分に大きい数）
static const int WHITE = 0; // ノードの色：未訪問
static const int GRAY = 1;  // ノードの色：訪問済み（キュー内）
static const int BLACK = 2; // ノードの色：処理済み

int n; // グラフのノード数
vector<pair<int, int> > adj[MAX]; // 重み付き有向グラフの隣接リスト表現

// ダイクストラ法による最短経路探索
void dijkstra() {
    priority_queue<pair<int, int> > PQ; // プライオリティキュー（優先度付きキュー）
    int color[MAX]; // ノードの状態を表す配列（WHITE, GRAY, BLACK）
    int d[MAX]; // 始点から各ノードへの最短距離を格納する配列

    // 全てのノードの初期化
    for ( int i = 0; i < n; i++ ) {
        d[i] = INFTY; // 最短距離を無限大に初期化
        color[i] = WHITE; // 全ノードを未訪問に初期化
    }

    d[0] = 0; // 始点ノードの距離を0に設定
    PQ.push(make_pair(0, 0)); // 始点をキューに追加
    color[0] = GRAY; // 始点を訪問済みに設定

    // キューが空になるまで処理を繰り返す
    while ( !PQ.empty() ) {
        pair<int, int> f = PQ.top(); PQ.pop(); // キューの最短距離ノードを取り出す
        int u = f.second; // 現在処理中のノード

        color[u] = BLACK; // ノードuを処理済みに設定

        // 最小値を取り出し、それが最短でなければ無視
        if ( d[u] < f.first * (-1) ) continue;

        // ノードuに隣接するノードvを調べる
        for ( int j = 0; j < adj[u].size(); j++ ) {
            int v = adj[u][j].first; // 隣接ノード
            if ( color[v] == BLACK ) continue; // 既に処理済みのノードはスキップ
            // 現在の経路がより短い場合、距離を更新
            if ( d[v] > d[u] + adj[u][j].second ) {
                d[v] = d[u] + adj[u][j].second; // 距離を更新
                // priority_queueはデフォルトで大きい値を優先するため-1を掛ける
                PQ.push(make_pair(d[v] * (-1), v)); // 更新後のノードをキューに追加
                color[v] = GRAY; // ノードvを訪問済みに設定
            }
        }
    }

    // 各ノードへの最短距離を出力
    for ( int i = 0; i < n; i++ ) {
        cout << i << " " << ( d[i] == INFTY ? -1 : d[i] ) << endl; // 到達不能なら-1を出力
    }
}

int main() {
    int k, u, v, c;

    // グラフの入力
    cin >> n; // ノード数の入力
    for ( int i = 0; i < n; i++ ) {
        cin >> u >> k; // ノードuの隣接ノード数k
        for ( int j = 0; j < k; j++ ) {
            cin >> v >> c; // 隣接ノードvとエッジの重みc
            adj[u].push_back(make_pair(v, c)); // 隣接リストに追加
        }
    }

    dijkstra(); // ダイクストラ法を実行

    return 0;
}
