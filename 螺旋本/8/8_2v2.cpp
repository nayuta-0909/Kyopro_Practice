#include <iostream>
using namespace std;
#define MAX 100005  // 最大ノード数
#define NIL -1      // ノードが存在しないことを示す値

// 木構造のノードを表す構造体
struct Node {
    int parent;   // 親ノードのインデックス（存在しない場合はNIL）
    int left;     // 左の子ノードのインデックス（存在しない場合はNIL）
    int right;    // 右の子ノードのインデックス（存在しない場合はNIL）
};

Node tree[MAX];  // 木のノードを格納する配列
int nodeCount, depth[MAX];  // nodeCountはノードの数、depthは各ノードの深さを格納する配列

// ノードの情報を表示する関数
void printNodeInfo(int nodeIndex) {
    cout << "node " << nodeIndex << ": ";
    cout << "parent = " << tree[nodeIndex].parent << ", ";
    cout << "depth = " << depth[nodeIndex] << ", ";

    // ノードの種類を判定
    if (tree[nodeIndex].parent == NIL) 
        cout << "root, ";
    else if (tree[nodeIndex].left == NIL) 
        cout << "leaf, ";
    else 
        cout << "internal node, ";

    // 子ノードのリストを表示
    cout << "[";
    for (int i = 0, child = tree[nodeIndex].left; child != NIL; i++, child = tree[child].right) {
        if (i > 0) cout << ",";
        cout << child;
    }
    cout << "]" << endl;
}

// ノードの深さを再帰的に計算する関数
void calculateDepth(int nodeIndex, int currentDepth) {
    depth[nodeIndex] = currentDepth;  // 現在のノードの深さを記録
    if (tree[nodeIndex].right != NIL) 
        calculateDepth(tree[nodeIndex].right, currentDepth);      // 右の兄弟がいる場合
    if (tree[nodeIndex].left != NIL) 
        calculateDepth(tree[nodeIndex].left, currentDepth + 1);  // 左の子がいる場合
}

int main() {
    int i, j, childCount, nodeIndex, childIndex, lastChild, rootIndex;

    // ノード数の入力
    cin >> nodeCount;

    // 全ノードの親・左の子・右の子をNILに初期化
    for (i = 0; i < nodeCount; i++) 
        tree[i].parent = tree[i].left = tree[i].right = NIL;

    // ノードの情報を入力
    for (i = 0; i < nodeCount; i++) {
        cin >> nodeIndex >> childCount;  // ノード番号とそのノードの子供の数を入力
        for (j = 0; j < childCount; j++) {
            cin >> childIndex;  // 子ノードの番号を入力
            if (j == 0) 
                tree[nodeIndex].left = childIndex;  // 最初の子を左の子に設定
            else 
                tree[lastChild].right = childIndex; // それ以外の子を右の兄弟に設定

            lastChild = childIndex;               // 子ノードを記録
            tree[childIndex].parent = nodeIndex;  // 子ノードの親を設定
        }
    }

    // 根ノードを探す（親がNILのノードが根）
    for (i = 0; i < nodeCount; i++) {
        if (tree[i].parent == NIL) {
            rootIndex = i;
            break;
        }
    }

    // 深さの計算を再帰的に実行
    calculateDepth(rootIndex, 0);

    // 全ノードの情報を出力
    for (i = 0; i < nodeCount; i++) 
        printNodeInfo(i);

    return 0;
}
