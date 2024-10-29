#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

// ノード構造体の定義。二分探索木の要素。
struct Node {
    int key;          // ノードのキー（値）
    Node *right;     // 右の子ノードへのポインタ
    Node *left;      // 左の子ノードへのポインタ
    Node *parent;    // 親ノードへのポインタ
};

// 木の根ノードとNIL（番兵ノード）をグローバルに宣言
Node *root, *NIL;

// 最小値を持つノードを返す関数
// 引数: Node *subtreeRoot - 最小値を探す部分木のルートノード
Node *treeMinimum(Node *subtreeRoot) {
    // 左の子が存在する限り左に進む
    while (subtreeRoot->left != NIL) subtreeRoot = subtreeRoot->left;
    return subtreeRoot; // 最も左にあるノードが最小値
}

// 値kを持つノードを探索する関数
// 引数: Node *currentNode - 探索を開始するノード
// 引数: int k - 探索するキーの値
Node *find(Node *currentNode, int k) {
    // ノードcurrentNodeがNILでなく、かつkとノードのキーが一致しない間ループ
    while (currentNode != NIL && k != currentNode->key) {
        if (k < currentNode->key) currentNode = currentNode->left;  // 探索値kが現在のノードより小さい場合、左の子へ
        else currentNode = currentNode->right;                       // 探索値kが現在のノードより大きい場合、右の子へ
    }
    return currentNode; // 見つけたノードを返す。見つからなければNILを返す
}

// 指定したノードの次の順番のノード（Successor）を探す関数
// 引数: Node *currentNode - Successorを探すノード
Node *treeSuccessor(Node *currentNode) {
    // 右の子が存在する場合、その部分木で最小のノードを返す
    if (currentNode->right != NIL) return treeMinimum(currentNode->right);

    // 右の子が存在しない場合、親ノードを辿ってSuccessorを見つける
    Node *parentNode = currentNode->parent;
    while (parentNode != NIL && currentNode == parentNode->right) {  // 親ノードが右の子である限り、親に進む
        currentNode = parentNode;
        parentNode = parentNode->parent;
    }
    return parentNode; // Successorが存在しなければNILを返す
}

// ノードを削除する関数
// 引数: Node *nodeToDelete - 削除するノード
void treeDelete(Node *nodeToDelete) {
    // 1. nodeToDelete: 二分探索木から削除されるノード
    Node *y; // 2. 削除するか、移動するノードを指す
    Node *x; // 3. yの子ノードを指す

    // 4. nodeToDeleteの左右の子がどちらか一方でもNILであれば、そのノードがyになる
    if (nodeToDelete->left == NIL || nodeToDelete->right == NIL) {
        y = nodeToDelete; // yを削除対象ノードnodeToDeleteに設定
    } else {
        y = treeSuccessor(nodeToDelete);  // nodeToDeleteのSuccessorをyに設定
    }

    // 5. yの左の子が存在すればそれをxとする。そうでなければ右の子をxとする
    if (y->left != NIL) {
        x = y->left; // xをyの左の子に設定
    } else {
        x = y->right; // xをyの右の子に設定
    }

    // 6. xがNILでなければ、xの親をyの親にする（子の置き換え）
    if (x != NIL) {
        x->parent = y->parent; // xの親をyの親に設定
    }

    // 7. yが根ノードであれば、根ノードをxに更新
    if (y->parent == NIL) {
        root = x; // 木の根ノードをxに設定
    } else {
        // 8. yが親の左の子であれば、yの親の左の子をxに更新
        if (y == y->parent->left) {
            y->parent->left = x; // yの親の左の子をxに設定
        } else {
            // 9. 右の子であれば右の子をxに更新
            y->parent->right = x; // yの親の右の子をxに更新
        }
    }

    // 10. yがnodeToDeleteと異なる場合、nodeToDeleteのキーをyのキーに更新
    if (y != nodeToDelete) {
        nodeToDelete->key = y->key; // nodeToDeleteのキーをyのキーに設定
    }

    // 11. yをメモリから解放
    free(y); // yのメモリを解放
}
