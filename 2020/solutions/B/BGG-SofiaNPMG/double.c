#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void *a, const void *b){
    const int *ia = (const int *)a;
    const int *ib = (const int *)b;

    return -((*ia > *ib) - (*ia < *ib));
}

int main(){
    int n, w1, w2;
    int sum = 0;
    scanf("%d", &n);
    scanf("%d", &w1);
    scanf("%d", &w2);
    int *a = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp_int);
    if(w1 < w2){
        int tmp = w1;
        w1 = w2;
        w2 = tmp;
    }


    free(a);

    return 0;
}
