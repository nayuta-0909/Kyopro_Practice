#include <stdio.h>
#include <string.h>

#define M 1046527  // ハッシュテーブルのサイズ
#define NIL (-1)   // NILの定義（使われていないインデックス）
#define L 14       // 文字列の最大長さ

char H[M][L];  // ハッシュテーブル

// 文字を数値に変換する関数
int getChar(char ch) {
    if (ch == 'A') return 1;
    else if (ch == 'C') return 2;
    else if (ch == 'G') return 3;
    else if (ch == 'T') return 4;
    else return 0;
}

// 文字列を数値キーに変換する関数
long long getKey(char str[]) {
    long long sum = 0, p = 1, i;
    for (i = 0; i < strlen(str); i++) {
        sum += p * (getChar(str[i]));  // 文字を数値に変換してキーを計算
        p *= 5;  // 5の累乗を計算
    }
    return sum;
}

// ハッシュ関数1
int h1(int key) { return key % M; }

// ハッシュ関数2
int h2(int key) { return 1 + (key % (M - 1)); }

// ハッシュテーブルから文字列を検索する関数
int find(char str[]) {
    long long key, i, h;
    key = getKey(str);  // 文字列を数値キーに変換
    for (i = 0;; i++) {
        h = (h1(key) + i * h2(key)) % M;  // 二重ハッシュ法でハッシュ値を計算
        if (strcmp(H[h], str) == 0) return 1;  // 文字列が見つかった場合
        else if (strlen(H[h]) == 0) return 0;  // 空の場所に到達した場合（存在しない）
    }
    return 0;
}

// ハッシュテーブルに文字列を挿入する関数
int insert(char str[]) {
    long long key, i, h;
    key = getKey(str);  // 文字列を数値キーに変換
    for (i = 0;; i++) {
        h = (h1(key) + i * h2(key)) % M;  // 二重ハッシュ法でハッシュ値を計算
        if (strcmp(H[h], str) == 0) return 1;  // 既に同じ文字列が存在する場合
        else if (strlen(H[h]) == 0) {  // 空の場所が見つかった場合
            strcpy(H[h], str);  // 文字列をハッシュテーブルに挿入
            return 0;
        }
    }
    return 0;
}

int main() {
    int i, n, h;
    char str[L], com[9];
    // ハッシュテーブルの初期化
    for (i = 0; i < M; i++) H[i][0] = '\0';
    
    // コマンドと文字列の入力
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s %s", com, str);

        // コマンドが "insert" の場合
        if (com[0] == 'i') {
            insert(str);
        } else {  // コマンドが "find" の場合
            if (find(str)) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }
    return 0;
}
