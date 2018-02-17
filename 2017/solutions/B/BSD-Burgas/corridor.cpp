#include <cstdio>
#define MAXN 100000
using namespace std;
int main()
{
    unsigned points[MAXN][2], w, h, n,area=0, swap;
    scanf("%u%u", &w, &h);
    scanf("%u", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%u%u", &points[i][0], &points[i][1]);
        if (i%2==1 && points[i-1][1]>points[i][1])
        {
            swap=points[i-1][1];
            points[i-1][1]=points[i][1];
            points[i][1]=swap;
        }
    }
    for (int i=0; i<n; i+=2)
    {
        for (int j=0; j<n; j+=2)
        {
            if (j==i || points[j][0]<points[i][0]) continue;
            if (points[i][1]>points[j][1] && points[i][1]<points[j+1][1])
            points[i][1]=points[j+1][1];
            if (points[i+1][1]>points[j][1] && points[i+1][1]<points[j+1][1])
            points[i+1][1]=points[j][1];

            if (points[i][1]>=points[i+1][1]) break;
        }
    }
    for (int i=0; i<n; i+=2)
    {
        if (points[i][1]>=points[i+1][1]) continue;
        area+=(points[i+1][1]-points[i][1])*(w-points[i][0]);
    }
    printf("%u\n", area);
    return 0;
}
