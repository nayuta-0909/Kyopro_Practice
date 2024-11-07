#include <iostream>
using namespace std;
#define MAX 100000

//node:iについての要素の計算
int parent(int i){return i /2;};//
int left(int i){return 2*i;};//左の子の値はは必ず偶数ノード
int right(int i){return 2*i + 1;};//右の子の値は必ず奇数ノード

int main(){
    int H,i,A[MAX+1];
    //nodeの数
    cin >> H;
    //keyの機能
    for(int i;i<=H;i++) cin >> A[i];

    //nodeの数だけループ
    for(i =1;i<H;i++){
        //keyの出力
        cout << "node" << i <<":key=" << A[i] << ",";
        if(parent(i)>= 1) cout << "parent key =" << A[parent(i)] << ",";
        if(left(i)<=H) cout << "left key =" << A[left(i)] << ",";
        if(right(i) <= H) cout << "right key =" << A[right(i)] << ",";
    }

    return 0;
}