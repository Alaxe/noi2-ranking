#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long brCifri,chislo;
    cin>>brCifri>>chislo;
//namirane na ostatuk
    long long ostatuk=1;
    for(int i=1; i<brCifri; i++)
    {
        ostatuk=(ostatuk*10)%chislo;
    }
    //cout<<ostatuk<<endl;
//namirane na broi cifri na ostatuk
    long long copOstatuk=ostatuk,brCifriNaOstatuk=0;
    while(copOstatuk!=0)
    {
        copOstatuk=copOstatuk/10;
        brCifriNaOstatuk++;
    }
//chasten sluchai za Ostatuk=0;
    if(ostatuk==0)
    {
        brCifriNaOstatuk=1;
        cout<<"1";
        for(int i=1; i<brCifri; i++)
        {
            cout<<"0";
        }
    }
//namirane na broi cifri na ostatuk-chislo
    long long copOstatuk2=chislo-ostatuk,brCifriNaOstatuk2=0;
    while(copOstatuk2!=0)
    {
        copOstatuk2=copOstatuk2/10;
        brCifriNaOstatuk2++;
    }
//namirane na broia na cifrite na k
    long long copK=chislo,brCifriChislo=0;
    while(copK!=0)
    {
        copK=copK/10;
        brCifriChislo++;
    }
//pri ostatuk!=0
    if(ostatuk!=0 && brCifriChislo!=brCifri)
    {
        cout<<"1";
        for(int i=1; i<=brCifri-brCifriNaOstatuk2-1; i++)
        {
            cout<<"0";
        }
        cout<<chislo-ostatuk;
    }
    if(brCifri==brCifriChislo)
    {
        cout<<chislo;
    }
    return 0;
}
