#include<iostream>
using namespace std;
char s[100][100];
long n, red=0, kol=0;
char prov;

int sumP(char a)
{
    if(a=='A')
        return 1;
    if(a=='T')
        return 10;
    if(a=='J')
        return 11;
    if(a=='Q')
        return 12;
    if(a=='K')
        return 13;
    if(a<='9'&&a>='0')
        return (int)(a-'0');
}

int chek1()
{
    long s1 = sumP(s[n-1][0]);
    red = n-1;
    kol = 1;
    while(!(kol==n-1&&red==0))
    {
        s1+=sumP(s[red][kol]);
        if(sumP(s[red][kol+1])>sumP(s[red-1][kol]))
            kol+=1;
        else
            red-=1;
    }
    s1+=sumP(s[0][n-1]);
    return s1;
}

int chek2()
{
    long s2 = sumP(s[n-1][0]);
    red = n-2;
    kol = 0;
    while(!(kol==n-1&&red==0))
    {
        s2 += sumP(s[red][kol]);
        if(sumP(s[red][kol+1])>sumP(s[red-1][kol]))
            kol+=1;
        else
            red-=1;
    }
    s2+=sumP(s[0][n-1]);
    return s2;
}

main ()
{
    cin >> n;
    for(long r = 0; r < n; r++)
    {
        for(long k = 0; k < n; k++)
        {
            cin >> s[r][k] >> prov;
        }
    }
    cout << max(chek1(), chek2()) << endl;
    return 0;
}
// ne nosi pulen broy tochki
/*
4
8S AD 3C AC
8C 4H QD QS
5D 9H KC 7H
TC QC AS 2D
*/
