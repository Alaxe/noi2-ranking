#include <iostream>
#define endl '\n'
using namespace std;
int mes[14]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int findden(int d, int m, int g)
{
    int br=0;
    if (m==2 && g==2020) mes[2]++;;
    while (d>mes[m])
    {
        m++;
        d-=mes[m-1];
        if (m>12) m-=12, g++;
    }
    if (g==2020)
    {
        for (int i=1; i<m; i++) br+=mes[i];
        br+=d;
        mes[2]--;
        return ((br%7)+2);
    }
    else if (g==2019)
    {
        for (int i=1; i<m; i++) br+=mes[i];
        br+=d;
        return ((br%7)+1);
    }
    else if (g==2021)
    {
        for (int i=1; i<m; i++) br+=mes[i];
        br+=d;
        return ((br%7)+4);
    }
}
void couting (int d, int m, int g)
{
    while (findden(d, m, g)>=6) d++;
    if (m==2 && g==2020) mes[2]++;
    while (d>mes[m])
    {
        m++;
        d-=mes[m-1];
        if (m>12) m-=12, g++;
    }
    if (d<10) cout << "0";
    cout << d << ".";
    if (m<10) cout << "0";
    cout << m << "." << g << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int d, m, g, br, den, week=0;
    char a;
    cin >> d >> a >> m >> a >> g;
    cin >> br;
    den=findden(d, m, g);
    if (br<=7-den)
    {
        if (br<=5-den) couting(d+br, m, g);
        else if (br>=6-den) couting (d+br+2, m, g);
    }
    else
    {
        if (den!=6 && den!=7) br-=(5-den);
        while (br>5) br-=5, week++;
        if (br<=4) couting(d+br+week*7+7-den, m, g);
    }
    return 0;
}
