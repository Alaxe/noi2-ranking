#include<cstdio>
int main()
{
    int n,W1,W2;
    int a;
    int F[201][201];
    int k,i,j;
    scanf("%d %d %d",&n,&W1,&W2);
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            F[i][j]=0;
    for(k=1;k<=n;k++)
    {
        scanf("%d",&a);
        for(i=W1;i>=1;i--)
            for(j=W2;j>=1;j--)
            {
                if(i>=a&&F[i-a][j]+a>F[i][j])
                    F[i][j]=F[i-a][j]+a;
                if(j>=a&&F[i][j-a]+a>F[i][j])
                    F[i][j]=F[i][j-a]+a;
            }
    }
    printf("%d\n",F[W1][W2]);
    return 0;
}
