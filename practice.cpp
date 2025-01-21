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

   Node *y =NIL;
   Node *x = root;
   Node *z;
   z->key = k;
   z->left =NIL;
   z->right = NIL;

   while( x != NIL){
        y = x;
        if(z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
        z->parent =y;
        if(y==NIL) {
            root =z;
        }else {
            if(z->key < y->key){
                y->left = z;
            }else {
                y->right =z;
            }
        }
   }
    
}

void inorder(Node *u) {
    if(u==NIL) return;
    inorder(u->left);
    printf("%d", u->key);
    inorder(u->left);
}

void preorder(Node *u){
    if(u==NIL) return;
    printf("%d" ,u->key);
    preorder(u->left);
    preorder(u->right);
}

int main() {
    /**
     * n:繰り返す回数
     * x:挿入する数値
     */
    int n,x;
    string com;

    scanf("%d", &n);

    for(int i=0;i<n;i++){
        cin >> com;
        if(com== "insert"){ 
            scanf("%d", &x);
            insert(x);
        } else if(com == "print"){
            printf("\n");
        }
    }
}
