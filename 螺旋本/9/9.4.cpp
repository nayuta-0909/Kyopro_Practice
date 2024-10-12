#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

// ノード構造体の定義。二分探索木の要素。
struct Node {
    int key;          // ノードのキー（値）
    Node *right, *left, *parent; // 右の子、左の子、親ノードへのポインタ
};

// 木の根ノードとNIL（番兵ノード）をグローバルに宣言
Node *root, *NIL;

// 最小値を持つノードを返す関数（部分木の中で最小の値を持つノードを見つける）
Node *treeMinimum(Node *x) {
    // 左の子が存在する限り左に進む
    while (x->left != NIL) x = x->left;
    return x; // 最も左にあるノードが最小値
}

// 値kを持つノードを探索する関数
Node *find (Node *u, int k) {
    // ノードuがNILでなく、かつkとノードのキーが一致しない間ループ
    while (u != NIL && k != u->key) {
        if (k < u->key) u = u->left;  // 探索値kが現在のノードより小さい場合、左の子へ
        else u = u->right;            // 探索値kが現在のノードより大きい場合、右の子へ
    }
    return u; // 見つけたノードを返す。見つからなければNILを返す
}

// 指定したノードxの次の順番のノード（Successor）を探す関数
Node *treeSuccessor(Node *x) {
    // 右の子が存在する場合、その部分木で最小のノードを返す
    if (x->right != NIL) return treeMinimum(x->right);

    // 右の子が存在しない場合、親ノードを辿ってSuccessorを見つける
    Node *y = x->parent;
    while (y != NIL && x == y->right) {  // 親ノードが右の子である限り、親に進む
        x = y;
        y = y->parent;
    }
    return y; // Successorが存在しなければNILを返す
}

// ノードを削除する関数
void treeDelete(Node *z) {
    Node *y; // 削除するか、移動するノードを指す
    Node *x; // yの子ノードを指す

    // zの左右の子がどちらか一方でもNILであれば、そのノードがyになる
    if (z->left == NIL || z->right == NIL) y = z;
    else y = treeSuccessor(z);  // そうでなければ、zのSuccessorをyにする

    // yの左の子が存在すればそれをxとする。そうでなければ右の子をxとする
    if (y->left != NIL) {
        x = y->left;
    } else {
        x = y->right;
    }

    // xがNILでなければ、xの親をyの親にする（子の置き換え）
    if (x != NIL) {
        x->parent = y->parent;
    }

    // yが根ノードであれば、根ノードをxに更新
    if (y->parent == NIL) {
        root = x;
    } else {
        // yが親の左の子であれば、yの親の左の子をxに更新
        if (y == y->parent->left) {
            y->parent->left = x;
        } else {
            y->parent->right = x;  // 右の子であれば右の子をxに更新
        }
    }

    // yがzと異なる場合、zのキーをyのキーに更新
    if (y != z) {
        z->key = y->key;
    }

    // yをメモリから解放
    free(y);
}
