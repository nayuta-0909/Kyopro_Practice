#include <stdio.h>
#include <string.h>
#define len 100005

typedef struct pp{
    char name[100];
    int t;
}p;

p q [len];
int head,tail,n;

void enqueue(p x){
    q[tail] = x;
    tail = (tail+1)%len;
}

p dequeue(){
    p x = q[head];
    head = (head+1)%len;
    return x;
}

int min(int a,int b){
    return a<b ? a :b;
}

int main(){
    int elaps = 0,c;
    int i,q;
    p u;
    scanf("%d %d",&n,&q);

    for(int i=1; i<=n;i++){
        scanf("%s",q[i].name);
        scanf("%d",&q[i].t);
    }

    head = 1,tail=n+1;

    while(head != tail){
        u = dequeue();
        c = min(q,u.t);
        u.t -= c;
        elaps += c;
        if(u.t>0) enqueue(u);
        else{
            printf("%s %d\n",u.name,elaps);
        }
    }

    return 0;
}
