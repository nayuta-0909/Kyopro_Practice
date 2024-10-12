#include <cstdio>
#define MAX 10000
#define NIL -1

struct  Node{int parent ,left ,right};
int n,D[MAX],H[MAX];

void setDepth(int u,int d){
    if(u==NIL) return;
    D[u] = d;
    setDepth(T[u].left,d+1);
    setDepth(T[u].right,d+1);
}

int setHeight(int u){
    int h1=0,h2=0;
    if(T[u].left != NIL)
        h1 = setHeight(T[u].left) + 1;
    if(T[u].right != NIL)
        h1 = setHeight(T[u].right) + 1;
    return H[u] = (h1>h2 ? h1 : h2);。
}