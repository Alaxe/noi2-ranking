#include<iostream>
using namespace std;
int vis(int go)
{
    if((go%4 == 0 && go%100 != 0) || (go%400 == 0)) return 1;
    else return 0;
}
int main ()
{
    int d, m, g, dni, vch=0;
    int dm[13]= {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char a;
    cin >> d >> a >> m >> a >> g >> dni;


    int god=2019, mes=1, den=1;
    bool tf=0;
    for( god = 2019; god <= g; god++)
    {
        if(vis(god)) dm[2] = 29;
        for (mes=1 ; mes <= m ; mes++)
        {
            if (mes == 13) mes = 1;
            if (mes != m)
            {
                for(den=1 ; den <= dm[mes]; den++)
                {
                    vch ++;
                    vch %= 7;

                }
            }
            if (mes == m && god == g)
            {
                for(den=1 ; den <= d; den++)
                {
                    vch ++;
                    vch %= 7;
                }
            }
        }
    }
    vch ++;
    vch %= 7;
    dni ++;
    den = d;
    for( god=g; ; )
    {
        if(vis(god)) dm[2] = 29;
        for ( mes = m; ; mes++)
        {
            if (mes == 13) mes = 1, god ++;
            if (mes == m && god == g)
            {
                for( den=d ; den <= dm[mes]; den++)
                {
                    vch ++;
                    vch %= 7;
                    if(vch != 0 && vch != 6) dni --;
                    if(dni == 0)
                    {
                        if(den < 10 && mes < 10)cout << "0" << den << ".0" << mes << "." << god << endl;
                        else if(den < 10 && mes > 9)cout << "0" << den << "." << mes << "." << god << endl;
                        else if(den > 9 && mes < 10)cout << den << ".0" << mes << "." << god << endl;
                        return 0;
                    }
                }
            }
            else
            {
                for(den=1 ; den <= dm[mes]; den++)
                {
                    vch ++;
                    vch %= 7;
                    if(vch != 0 && vch != 6) dni --;
                    if(dni == 0)
                    {
                        if(den < 10 && mes < 10)cout << "0" << den << ".0" << mes << "." << god << endl;
                        else if(den < 10 && mes > 9)cout << "0" << den << "." << mes << "." << god << endl;
                        else if(den > 9 && mes < 10)cout << den << ".0" << mes << "." << god << endl;
                        return 0;
                    }
                }
            }
        }

    }
}

