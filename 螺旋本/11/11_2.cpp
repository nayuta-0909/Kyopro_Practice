#include <iostream>
using namespace std;

int dp[50]; // Fibonacci数を格納する配列

// n番目のFibonacci数を計算する関数
int fib(int n) {
    if (n == 0 || n == 1) return dp[n] = 1; // 基底ケース
    if (dp[n] != -1) return dp[n]; // メモ化された値を返す
    return dp[n] = fib(n - 1) + fib(n - 2); // 再帰的に計算
}

int main() {
    int n; // Fibonacci数の位置
    int F[50]; // Fibonacci数を格納する配列

    // 配列の初期化
    for (int i = 0; i < 50; i++) dp[i] = -1; // メモ化用の配列を-1で初期化

    cout << "Fibonacci数の位置を入力してください: ";
    cin >> n; // ユーザーから位置を入力

    // Fibonacci数を計算
    for (int i = 0; i <= n; i++) {
        F[i] = fib(i); // Fibonacci数を計算して配列に格納
    }

    // 結果を表示
    cout << "Fibonacci数: ";
    for (int i = 0; i <= n; i++) {
        cout << F[i] << " "; // 各Fibonacci数を出力
    }
    cout << endl;

    return 0; // プログラムを終了
}
