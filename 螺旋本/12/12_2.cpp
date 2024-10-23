#include <iostream>  
using namespace std; 
static const int N = 100;

int main(){
    int M[N][N];  // N x Nの2次元配列Mを定義。隣接行列を表す。
    int n, u, k, v;  // nは頂点数、uは頂点、kはその頂点から出る辺の数、vは隣接する頂点を表す。

    // 頂点数nを入力
    cin >> n;

    // 初期化: 行列Mのすべての要素を0に設定（辺がない状態）
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            M[i][j] = 0;  // 隣接行列をゼロで初期化
        }
    }

    // 各頂点について、入力された隣接する頂点に対応する行列の値を1にする
    for(int i = 0; i < n; i++){
        cin >> u >> k;  // 頂点uとその隣接する頂点の数kを入力
        u--;  // 頂点番号を0始まりに調整（入力は1始まり）
        for(int j = 0; j < k; j++){
            cin >> v;  // 隣接する頂点vを入力
            v--;  // 同じく0始まりに調整
            M[u][v] = 1;  // 頂点uから頂点vへ辺があることを行列Mに反映
        }
    }

    // 隣接行列を出力
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j) cout << "";  // ここは何も出力していないため、不要なコード
            cout << M[i][j];  // 行列の値を出力
        }
        cout << endl;  // 行の終わりで改行
    }

    return 0;  // プログラムの正常終了
}
