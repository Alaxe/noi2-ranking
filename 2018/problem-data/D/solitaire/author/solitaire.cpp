// Task - solitaire
//Author - Plamenka Hristova

#include <stdio.h>
#include <string.h>
using namespace std;

int v[110][110], n, bes[110][110];
char s[3];
int big (int a, int b)
{ return (a>b)?a:b; }
main (){
    int i,j;
    scanf("%d",&n);
    for (i = 1; i <= n; i++)
        for (j = 1; j  <= n; j++) {
          scanf("%s",s);
          v[i][j]= (s[0]=='T')?10: (s[0]=='J')?11:(s[0]=='Q')?12:
                   (s[0]=='K')?13: (s[0]=='A')?1: (s[0]-'0');}

    memset (bes, 0, sizeof (bes));
    for (i = n; i > 0; i--)
        for (j = 1; j <= n; j++)
            bes[i][j] = big (bes[i+1][j], bes[i][j-1]) + v[i][j];
    printf ("%d\n", bes[1][n]);
    return 0;
}
