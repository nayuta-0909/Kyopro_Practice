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

    for( int i=0; i<n;i++) {
        cin >> u >> k;
        u--;
        for(int j=0;j<k;j++){
            cin >> v;
            M[i] [j] = 1;
        }
    }

}