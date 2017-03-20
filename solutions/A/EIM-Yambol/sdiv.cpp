#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

char str[10011];
int n;
Int m;
Int F[2][10011];

int main()
{
    int i,j;
    int cur,op;
    int L;
    int num;

    scanf("%s",str+1);
    L=strlen(str+1);

    scanf("%d %lld",&n,&m);

    F[0][0]=1;

    for (i=1;i<=L;i++)
    {
        cur=i%2;
        op=cur^1;
        num=str[i]-'0';

        for (j=0;j<n;j++)
        {
            F[cur][j]+=F[op][j];
            if (F[cur][j]>=m)
            F[cur][j]-=m;

            F[cur][ (j*10+num)%n ]+=F[op][j];
            if (F[cur][ (j*10+num)%n ]>=m)
            F[cur][ (j*10+num)%n ]-=m;

            F[op][j]=0;
        }
    }

    F[cur][0]--;
    if (F[cur][0]<0)
    F[cur][0]+=m;

    printf("%lld\n",F[cur][0]);

    return 0;
}
