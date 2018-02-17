#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

pair<int,int> myq[10000111];
int qL=0,uk=1;
int n,k;
Int FIRST,MUL,ADD,MOD;

int main()
{
    int i,j;
    Int NUMBER;
    int num;
    Int ans=0;

    scanf("%d %d",&n,&k);

    scanf("%lld %lld %lld %lld",&FIRST,&MUL,&ADD,&MOD);

    for (i=1;i<=n;i++)
    {
        if (i==1)
        NUMBER=FIRST;
        else
        NUMBER=(NUMBER*MUL+ADD)%MOD;

        num=(int)NUMBER;

        while(qL>=uk)
        {
            if (myq[qL].first<num)
            {
                qL--;
            }
            else
            break;
        }

        qL++;
        myq[qL]=make_pair(num,i);

        while(uk<=qL)
        {
            if (i-myq[uk].second+1>k)
            {
                uk++;
            }
            else
            break;
        }

        ans+=myq[uk].first;
    }

    printf("%lld\n",ans);

    return 0;
}
