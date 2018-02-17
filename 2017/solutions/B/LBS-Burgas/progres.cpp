#include <cstdio>
#define MAXN 1000
int A[MAXN], N, D=1, n=0;

void red(int x)
{
    for(int a=x+1; a<=N; a++)
    {
        if(A[a] - A[x] == D)
        {
            n++;
            if(a!=N-1) {red(a);}
        }
    }
}

int main()
{
    int maxA=0, minA=MAXN;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        scanf("%d", (A+i));
        if(A[i]<minA) minA = A[i];
        if(A[i]>maxA) maxA = A[i];
    }
    for(int i=0;i<N; i++)
    {
        if(A[i]!=maxA)
        {
            while((maxA - minA) - D + 1)
            {
                red(i); D++;n%=123456789012345;
            }
        }
        D=1;
    }
    printf("%d", n);
    return 0;
}
