#include <cstdio>
#define MAXN 999
using namespace std;
char result[15], cifri;
unsigned n, red[MAXN], d;
void found_one(unsigned c)
{
    result[c]++;
    if (result[c]>9)
    {
        if (c==0)
        {
            result[c]=1;
            cifri++;
            return;
        }
        result[c]=0;
        found_one(c-1);
    }
    if (cifri<15) return;
    for (int i=0; i<15; i++) if (result[i]!=(i+1)%10) return;
    cifri=1;
    for (int i=0; i<15; i++) result[i]=0;
}
void count_progres(unsigned begini, int came)
{
    for (int i=begini+1; i<n; i++)
    {
        if (red[begini]+d==red[i])
        {
            count_progres(i, begini);
        }
    }
    if (came!=-1) found_one(cifri-1);
}
int main()
{
    unsigned minE, maxE;
    for (int i=0; i<15; i++) result[i]=0;
    cifri=1;
    scanf("%u", &n);
    scanf("%u", &red[0]);
    minE=red[0];
    maxE=red[0];
    for (int i=1; i<n; i++)
    {
        scanf("%u", &red[i]);
        if (red[i]>maxE) maxE=red[i];
        if (red[i]<minE) minE=red[i];
    }
    for (d=1; d<=maxE-minE; d++) for (int begini=0; begini<n-1; begini++)
    count_progres(begini, -1);
    for (int i=0; i<cifri; i++) printf("%d", (int)result[i]);
    printf("\n");
    return 0;
}
