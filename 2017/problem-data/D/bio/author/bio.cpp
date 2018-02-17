//Task bio
//Author Pano Panov

#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX_SIZE 25000

using namespace std;
char markMax[MAX_SIZE];

int dcvt(char *t){
    int day, month;
    int sm[]={0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    sscanf(t,"%d/%d",&day,&month);
    return sm[month-1]+day;
}

int main() {
    int a, b, c, d, i;
    char bac[24], bbc[24], bcc[24], bdc[24];
        scanf(" %s %s %s %s", bac, bbc, bcc, bdc);
        a=dcvt(bac);
        b=dcvt(bbc);
        c=dcvt(bcc);
        d=dcvt(bdc);

        a = (a + 368 - d) % 23;
        b = (b + 392 - d) % 28;
        c = (c + 396 - d) % 33;

        memset(markMax, 0, sizeof(markMax));
        for(i = b; i < MAX_SIZE; i += 28) markMax[i]++;
        for(i = c; i < MAX_SIZE; i += 33) markMax[i]++;
        for(i = a ? a : 23; i < MAX_SIZE && markMax[i] != 2; i += 23);
        printf("%d\n",  i);
        return 0;
}
