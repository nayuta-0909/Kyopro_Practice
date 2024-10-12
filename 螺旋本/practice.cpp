#include <stdio.h>
#include <string.h>

#define M 1046527
#define NIL(-1)
#define L 14

char H[M][L]

int h1(int key){return key % M};
int h2(int key){return 1+(key % (M-1));}

int insert(char srt[]){
    long long key,i,h;
    key= getkey(str);
    for(i=0;;i++){
        h = (h1(key) + i*h2(key)) % M;
        if(strcmp(H[h],str)==0) return 1;
        else if(strlen(H[h]==0)){
            strcpy(H[h],str);
            return 0;
        }
    }
}



int main(){
    int i,n,h;
    char str[L],com[9]
    for(i=0;i<M;i++)    H[i][0] = '0'
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s %s",com,str);

        if(com[0]=="i"){
            insert(str);
        }else{
            if(find(str)){
                printf("yes");
            }else{
                printf("no")
            }
        }
    }
}