// Task - grip
// Author - Pano Panov
#include <stdio.h>

using namespace std;

bool IsLeapYear(int year){
    if (year % 400 == 0) return true;
    if ((year % 4 == 0) && (year % 100 != 0)) return true;
    return false;
}

int dayofweek(int d, int m, int y){
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return ( y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

void nextday(int *d, int *m, int *y){
    int mdays[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(IsLeapYear(*y)) mdays[1]=29;
    if(*d+1 <= mdays[*m-1]) (*d)++;
    else{
         if(*m+1 <=12){
            (*m)++;
            *d=1;
         }
         else{
            (*y)++;
            *m =1;
            *d=1;
         }
    }
}
int main(){
    int sy, sm, sd, brdays;
    int s=0, j;
    scanf("%d/%d/%d", &sd, &sm, &sy);
    scanf("%d", &brdays);
    for(;;){
        j = dayofweek(sd, sm, sy);
        if(j>0 && j<6) break;
        nextday(&sd, &sm, &sy);
    }
    while(s < brdays){
         nextday(&sd, &sm, &sy);
         j = dayofweek(sd, sm, sy);
         if(j>0 && j<6 ) s++;

    }
    for(;;){
        j = dayofweek(sd, sm, sy);
        if(j>0 && j<6) break;
        nextday(&sd, &sm, &sy);
    }
    printf("%02d.%02d.%d\n",sd, sm, sy);
    return 0;
}
/* End of File */
