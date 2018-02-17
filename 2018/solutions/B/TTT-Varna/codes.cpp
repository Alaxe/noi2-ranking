#include <iostream>
using namespace std;
int n, k, a, b, dig1, dig2, maxdif, dif;
unsigned long long maxn;
struct num
{
    unsigned long long v;
    int sum;
}mas[1030];
void generate_row(int len, unsigned long long stepten)
{
    for (int i=len+1; i<=2*len; i++)
    {
        mas[i].v=mas[2*len-i+1].v;
        mas[i].v=(unsigned long long)dig2*stepten+mas[i].v;
        mas[i].sum=mas[2*len-i+1].sum+dig2;
    }
    for (int i=1; i<=len; i++)
    {
        mas[i].v=(unsigned long long)dig1*stepten+mas[i].v;
        mas[i].sum+=dig1;
    }
}
int main ()
{
    cin >>n>>k>>a>>b;
    cin >>dig1>>dig2;
    mas[1].v=dig1;
    mas[1].sum=dig1;
    mas[2].v=dig2;
    mas[2].sum=dig2;
    int steptwo=2;
    unsigned long long stepten=10;
    for (int i=2; i<=k; i++)
    {
        generate_row(steptwo, stepten);
        steptwo*=2;
        stepten*=10;
    }
    for (int i=a; i<b; i++)
    {
        if (mas[i].v>maxn) maxn=mas[i].v;
        dif=mas[i].sum-mas[i+1].sum;
        if (dif<0) dif=-dif;
        if (dif>maxdif) maxdif=dif;
    }
    if (mas[b].v>maxn) maxn=mas[b].v;
    cout <<maxn<<" "<<maxdif<<endl;
}
