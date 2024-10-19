#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

struct Node{
    int key;
    Node *parent,*left,*right;
};

Node *root,*NIL;

Node *find(Node *u,int k){
    while(u != NIL && k != u->key){
        if(k < u->key) u = u->left;
        else u = u -> right;
    }
    return u;
}

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

void inorder(Node *u){

}

void preorder(Node *u){

}


int main(){
    int n,i,x;
    string com;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        cin >> com;
        if(com[0] == 'f'){
            scanf("%d",&x);
            Node *t = find(root,x);
            if(t != NIL) printf("yes\n");
            else printf("no\n");
        }else if(com =="print"){
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
        }
    }
}
