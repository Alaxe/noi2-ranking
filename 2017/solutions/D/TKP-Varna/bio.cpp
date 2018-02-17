#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string fiz, e, in, d;
    cin >> fiz >> e >> in >> d;

    int fd = 0, fm = 0;
    int ed = 0, em = 0;
    int id = 0, im = 0;
    int dd = 0, dm = 0;
    int meseci[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int i;
    int n = 10;
    //-------------------------------------------------
    if(fiz[1] == '/') n = 1;
    for(i = 0; fiz[i] != '/'; i++) /// FIZICHESKI CIKUL
    {
        fd += (fiz[i] - '0')*n;
        n = 1;
    }

    if(i + 1 == fiz.length() - 1) n = 1;
    else n = 10;
    for(i = i + 1; i < fiz.length(); i++)
    {
        fm = (fiz[i] - '0')*n;
        n = 1;
    }
    //-------------------------------------------------

    n = 10;
    if(e[1] == '/') n = 1;
    for(i = 0; e[i] != '/'; i++) /// EMOCIONALEN CIKUL
    {
        ed += (e[i] - '0')*n;
        n = 1;
    }

    if(i + 1 == e.length() - 1) n = 1;
    else n = 10;
    for(i = i + 1; i < e.length(); i++)
    {
        em = (e[i] - '0')*n;
        n = 1;
    }
    //-------------------------------------------------

    n = 10;
    if(in[1] == '/') n = 1;
    for(i = 0; in[i] != '/'; i++) /// INTELEKTUALEN CIKUL
    {
        id += (in[i] - '0')*n;
        n = 1;
    }
    if(i + 1 == in.length() - 1) n = 1;
    else n = 10;
    for(i = i + 1; i < in.length(); i++)
    {
        im = (in[i] - '0')*n;
        n = 1;
    }
    //-------------------------------------------------

    n = 10;
    if(d[1] == '/') n = 1;
    for(i = 0; d[i] != '/'; i++) /// DATA SPRQMO KOQTO TURSIM
    {
        dd += (d[i] - '0')*n;
        n = 1;
    }

    if(i + 1 == d.length() - 1) n = 1;
    else n = 10;
    for(i = i + 1; i <d.length(); i++)
    {
        dm = (d[i] - '0')*n;
        n = 1;
    }
    //-------------------------------------------------

    int maksF = 0, maksE = 0, maksI = 0;

    while(true)
    {
        maksF += 23;
        maksE += 28;
        maksI += 33;
        if(maksF == maksE == maksI)
        {
            cout<<maksF<<endl;
            return 0;
        }
    }

    cout<<fd<<"/"<<fm<<" "<<ed<<"/"<<em<<" "<<id<<"/"<<im<<" "<<dd<<"/"<<dm<<endl;
}
