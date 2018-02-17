#include <stdio.h>

int n, ch[999];
long long izh, how[1000][1000];

int main () {
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        scanf("%d", ch + i);
        for(int j = 0; j < i; j ++) {
            if(ch[i] > ch[j]) {
                how[i][ch[i] - ch[j]] += how[j][ch[i] - ch[j]] + 1;
                izh += how[j][ch[i] - ch[j]] + 1;
            }
            how[i][ch[i] - ch[j]] %= 123456789012345;
            izh %= 123456789012345;
        }
    }
    printf("%lld\n", izh);
    return 0;
}
