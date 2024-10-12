#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Node{
    int key;
    Node *next,*prev;
};

Node *nil;

Node* listsearch(int key){
    Node *cur = nil -> next;
    while(cur != nil && cur ->key != key){
        cur = cur -> next;
    }
    return cur;
}

void init(){
    nil = (Node *)malloc(sizeof(Node));
    nil ->next = nil;
    nil -> prev = nil;
}                                                                   