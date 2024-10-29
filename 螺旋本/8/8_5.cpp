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


Node* root, *NIL;

void insert(int k){
    /*
    二分探索木に新しいノードを挿入する関数

    k: 挿入する値
    x: 現在比較しているノード（挿入場所を探すために使う）
    y: xの親ノード（新しいノードが挿入される場所の親）
    z: 挿入するノード
    */
   Node *x=NIL;
   Node *y= NIL;
   Node *z;
    z = (Node*)malloc(sizeof(Node));  // 新しいノードのメモリを確保
    z->key = k;           // 新しいノードの値を設定
    z->left = NIL;        // 左の子ノードはNIL（初期状態では子を持たない）
    z->right = NIL;       // 右の子ノードもNIL


    while(x != NIL){
        y =x;
        if(z->key < x->key){
            x = x->left;
        }
        else {
            x = x->left;
        }
    }

    z->parent = y;
    if( y ==NIL){
        root = z;
    }
    else{
        if(z->key < y->key){
            y->left = z;
        }
        else{
            y->right = z;
        }
    }
}

Node *find(Node *u, int k){
    while(u != NIL && k != u->key){
        if(k <u->key) u = u->left;
        else  u = u->right;
    }
    return u;
}