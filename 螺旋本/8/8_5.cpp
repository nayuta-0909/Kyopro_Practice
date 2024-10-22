#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n, pos; // ノード数と現在の位置
vector<int> pre, in, post; // 前順序、中順序、後順序のベクター

// 再帰関数
void rec(int l, int r) {
    if (l >= r) return; // 範囲が無効な場合は終了
    int root = pre[pos++]; // 前順序からルートを取得
    int m = distance(in.begin(), find(in.begin(), in.end(), root)); // ルートのインデックスを取得
    rec(l, m); // 左部分木を再帰的に処理
    rec(m + 1, r); // 右部分木を再帰的に処理
    post.push_back(root); // 後順序にルートを追加
}

// 解決関数
void solve() {
    pos = 0; // 現在の位置を初期化
    rec(0, pre.size()); // 再帰的にトラバース
    for (int i = 0; i < post.size(); i++) { // 後順序のノードを表示
        if (i) cout << " "; // 最初の要素以外はスペースを挿入
        cout << post[i]; // ノードを表示
    }
    cout << endl; // 改行
}

int main() {
    int k; // 一時変数
    cin >> n; // ノード数を入力

    // 前順序を入力
    for (int i = 0; i < n; i++) {
        cin >> k; // ノードを入力
        pre.push_back(k); // 前順序に追加
    }

    // 中順序を入力
    for (int i = 0; i < n; i++) {
        cin >> k; // ノードを入力
        in.push_back(k); // 中順序に追加
    }

    solve(); // 解決関数を呼び出す

    return 0; // プログラムを終了
}
