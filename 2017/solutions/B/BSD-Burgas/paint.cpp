#include <cstdio>
#define MAXN 11000
using namespace std;
unsigned rec[MAXN][4], ans[MAXN];
bool point_in_rec(unsigned x, unsigned y, unsigned reci)
{
    return x>rec[reci][0] && x<rec[reci][0]+rec[reci][2]
    && y>rec[reci][1] && y<rec[reci][1]+rec[reci][3];
}
unsigned get_area(unsigned reci, unsigned n)
{
    unsigned area=rec[reci][2]*rec[reci][3];
    for (unsigned i=0; i<n; i++)
    {
        if (i==reci) continue;
        if (point_in_rec(rec[i][0], rec[i][1], reci)) area-=get_area(i, n);
    }
    return area;
}
int main()
{
    unsigned n, t, x, y, sml_reci, sml_reca;
    rec[0][0]=rec[0][1]=0;
    scanf("%u%u", &rec[0][2], &rec[0][3]);
    scanf("%u", &n);
    n++;
    for (int i=1; i<n; i++)
    scanf("%u%u%u%u", &rec[i][0], &rec[i][1], &rec[i][2], &rec[i][3]);
    scanf("%u", &t);
    for (int i=0; i<t; i++)
    {
        sml_reca=rec[0][2]*rec[0][3];
        sml_reci=0;
        scanf("%u%u", &x, &y);
        for (int j=1; j<n; j++)
        {
            unsigned curr_area=rec[j][2]*rec[j][3];
            if (point_in_rec(x, y, j) && curr_area<sml_reca)
                {
                    sml_reci=j;
                    sml_reca=curr_area;
                }
        }
        ans[i]=get_area(sml_reci, n);
    }
    for (int i=0; i<t; i++) printf("%u\n", ans[i]);
    return 0;
}

