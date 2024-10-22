#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 文字列XとYのLCSを計算する関数
int lcs(string X, string Y) {
    int m = X.size(); // Xの長さ
    int n = Y.size(); // Yの長さ
    int maxl = 0; // LCSの最大長さ

    // dpテーブルの初期化
    vector<vector<int>> c(m + 1, vector<int>(n + 1, 0));

    // dpテーブルの構築
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) { // 文字が一致する場合
                c[i][j] = c[i - 1][j - 1] + 1; // 対応する前の値に1を加算
            } else { // 一致しない場合
                c[i][j] = max(c[i - 1][j], c[i][j - 1]); // 最大の値を取得
            }
            maxl = max(maxl, c[i][j]); // 最大長さを更新
        }
    }
    return maxl; // LCSの長さを返す
}

int main() {
    string s1, s2; // 2つの文字列
    int n;

    cout << "2つの文字列の長さを入力してください: ";
    cin >> n; // 文字列の長さを入力

    cout << "文字列1を入力してください: ";
    cin >> s1; // 1つ目の文字列を入力

    cout << "文字列2を入力してください: ";
    cin >> s2; // 2つ目の文字列を入力

    cout << "LCSの長さ: " << lcs(s1, s2) << endl; // LCSの長さを表示

    return 0; // プログラムを終了
}
