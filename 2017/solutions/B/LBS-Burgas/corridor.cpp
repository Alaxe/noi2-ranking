#include <cstdio>
#include <algorithm>
#define MAXN 100000
int vert[3][MAXN];

int main()
{
    int w, h; scanf("%d %d", &w, &h);
    int N; scanf("%d", &N);
    for(int i=0; i<3; i++)
        for(int j=0; j<100000; j++)
        {
            vert[i][j] = 0;
        }

    int a1, a2, b1, b2;
    scanf("%d %d", &a1, &a2); N--;
    for(int i=0;i<N; i++)
    {
        scanf("%d %d", &b1, &b2);
        if(a1 == b1)
        {
            vert[0][i] = a1;
            vert[1][i] = std::min(a2,b2);
            vert[2][i] = std::max(a2,b2);
        }
        a1 = b1; a2 = b2;
    }

    for(int i=N-1; i>=0; i--)
        {for(int j=i-1; j>=0; j--)
            {
                if(vert[0][i] > vert[0][j])
                {
                    std::swap(vert[0][i], vert[0][j]);
                    std::swap(vert[1][i], vert[1][j]);
                    std::swap(vert[2][i], vert[2][j]);
                }
            }}
    int S=0;
    for(int i=0; i<h; i++)
        for(int j=0; j<= N; j++)
    {
        if(vert[1][j] <= i && i < vert[2][j])
        {
            S += w - vert[0][j];
            break;
        }
    }

    printf("%d", S);
    return 0;
}
