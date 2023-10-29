#include <stdio.h>
#include <string.h>
int N, K, hash[50][27];
char word[50][16];//input
int req[50];//몇 개의 알파벳이 더 있어야 읽을 수 있는지
int learned[27] = {
    0,'n' - 'a' + 1,'t' - 'a' + 1, 'i' - 'a' + 1, 'c' - 'a' + 1,'a' - 'a' + 1,
};//모든 문자열에 a,n,t,i,c가 들어있으니 이건 우선적으로 넣고 하자
int res;
int check() {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        int get_to_know = 0;//새롭게 알게 됀 문자
        for (int j = 1; j <= K; j++) {
          if (hash[i][learned[j]] == 1)get_to_know++;
        }
        if (req[i] == get_to_know)ret++;
    }
    return ret;
}
void back_tracking(int cnt) {
    if (cnt == K + 1) {
        int ret = check();
        if (res < ret)res = ret;
        return;
    }
    for (int i = learned[cnt - 1] + 1; i <= 26; i++) {
        if (
            i == 'a' - 'a' + 1 ||
            i == 'n' - 'a' + 1 ||
            i == 't' - 'a' + 1 ||
            i == 'i' - 'a' + 1 ||
            i == 'c' - 'a' + 1
            )continue;
        learned[cnt] = i;
        back_tracking(cnt + 1);
    }
}
int main() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%s", word[i]);
        int len = strlen(word[i]);
        for (int j = 0; j < len; j++) {
            if (hash[i][word[i][j] - 'a' + 1] == 0) {
                if (
                    word[i][j] == 'a' - 'a' + 1 ||
                    word[i][j] == 'n' - 'a' + 1 ||
                    word[i][j] == 't' - 'a' + 1 ||
                    word[i][j] == 'i' - 'a' + 1 ||
                    word[i][j] == 'c' - 'a' + 1
                    )continue;
                hash[i][word[i][j] - 'a' + 1] = 1;
                req[i]++;
            }
        }
    }
    if (K < 5) {
        printf("0");
        return 0;
    }
    back_tracking(6);
    printf("%d", res);
}