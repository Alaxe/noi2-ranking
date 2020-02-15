#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int N, U;

int cmp_int(const void *a, const void *b){
    const int *ia = (const int *)a;
    const int *ib = (const int *)b;

    return (*ia > *ib) - (*ia < *ib);
}


/*
int un_red_count(int cbr, int br){
    int count = 0;

    if(cbr < U - br - 1){
        for(int i = cbr; i <= U-br; i++){
            count += un_red_count(i + 1, br);
            printf("%d ", count);
        }
    }
    else{
        count += U - br - cbr + 1;
        printf("%d ", count);
    }

    return count;
}

*/
int un_red_count(int cb, int br){
    int count = 0;
    for(int i = cb; i <= U; i++){
        count += U - (br + i - 1);
        //count += U - (br + i);
    //printf("%d\n", count);
    }
    if(cb != br){
        count += un_red_count(cb + 1, br);
    }

    return count;
}

int main(){
    scanf("%d", &N);
    scanf("%d", &U);
    int *arr = malloc(sizeof(int) * N);
    int *sarr = malloc(sizeof(arr));
    int min = INT_MAX, max = INT_MIN;
    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
        sarr[i] = arr[i];
    }
    qsort(sarr, N, sizeof(int), cmp_int);

    min = sarr[0];
    max = sarr[N - 1];
    if(min == max){
        int mid = (U + 1) / 2;
        printf("%d", (U + 1) / 2);
        for(int i = 1; i < N; i++){
            printf(" %d", (U + 1) / 2);
        }
        printf("\n");
        return 0;
    }


    int br = 0;
    for(int i = 1; i < N; i++){
        if(sarr[i] > sarr[i - 1]){
            br++;
        }
    }

    //printf("br: %d\n", br);

    int count = un_red_count(br, 1);
    count = (count + 1) / 2;
    //printf("Count: %d\n", count);

    for(int i = 0; i < count; i++){
        //
    }

    free(arr);
    free(sarr);

    return 0;
}
