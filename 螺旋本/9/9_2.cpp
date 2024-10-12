#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

// 二分探索木（BST）のノード構造体を定義
struct Node {
    int key;          // ノードの値
    Node* right;      // 右の子ノードへのポインタ
    Node* left;       // 左の子ノードへのポインタ
    Node* parent;     // 親ノードへのポインタ
};

// 木の根(root)とNIL（番兵ノード）を宣言
Node* root, * NIL;

void insert(int k) {
    /*
    二分探索木に新しいノードを挿入する関数

    k: 挿入する値
    x: 現在比較しているノード（挿入場所を探すために使う）
    y: xの親ノード（新しいノードが挿入される場所の親）
    z: 挿入するノード
    */

    // 初期化
    Node* y = NIL;        // yはxの親ノードとして使う
    Node* x = root;       // xは現在探索中のノードとして使う
    Node* z;              // 挿入する新しいノード
    z = (Node*)malloc(sizeof(Node));  // 新しいノードのメモリを確保
    z->key = k;           // 新しいノードの値を設定
    z->left = NIL;        // 左の子ノードはNIL（初期状態では子を持たない）
    z->right = NIL;       // 右の子ノードもNIL

    // 挿入位置を見つけるための探索ループ
    while (x != NIL) {    // xがNILでない限り（木の末端でない限り）
        y = x;            // yを親ノードとして保存
        if (z->key < x->key) {
            x = x->left;  // 挿入する値が現在のノードより小さい場合、左に移動
        }
        else {
            x = x->right; // 挿入する値が現在のノードより大きい場合、右に移動
        }
    }
    /////////////////////////////////

    // 挿入
    z->parent = y;        // 新しいノードzの親をyに設定

    if (y == NIL) {       // 木が空の場合、新しいノードzを根にする
        root = z;
    }
    else {
        if (z->key < y->key) {
            y->left = z;  // 新しいノードzをyの左の子として挿入
        }
        else {
            y->right = z; // 新しいノードzをyの右の子として挿入
        }
    }
    /////////////////////////////////
}
