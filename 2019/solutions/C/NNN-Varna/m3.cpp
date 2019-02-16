#include <bits/stdc++.h>
using namespace std;
long long s, k, a, b, c, d;
void cout_3p(double c, bool se)
{
    int cl=(int)((c-(int)c)*1000);
    cout << (int)c << ".";
    if (cl<10) cout << "00";
    else if (cl<100) cout << "0";
    if ((int)((c-(int)c)*10000)%10>=5) cout << cl+1;
    else cout << cl;
    if (se) cout << endl;
    else cout << " ";
}
int main()
{
    cin >> s >> k >> a >> b >> c >> d;
    long long bg=max(a, max(b, max(c, d))), ima, imb, imc, imk=k%(bg*4);
    if (k/(bg*4)>=s)
    {
        double afafn = (double)(k/(s*4));
        cout_3p(afafn, 0);
        cout_3p(afafn, 0);
        cout_3p(afafn, 0);
        cout_3p(afafn, 1);
        return 0;
    }
         if ((k/(bg*4))%4==0) ima=a, imb=c, imc=b;
    else if ((k/(bg*4))%4==1) ima=b, imb=a, imc=c;
    else if ((k/(bg*4))%4==2) ima=b, imb=c, imc=a;
    else if ((k/(bg*4))%4==3) ima=c, imb=a, imc=b;
    if (imk>=bg*4)
    {
        double afafn = (double)(imk)/4;
        cout_3p(afafn, 0);
        cout_3p(afafn, 0);
        cout_3p(afafn, 0);
        cout_3p(afafn, 1);
        return 0;
    }
    if (imk<=ima)
    {
        double afafn = (double)(imk);
        cout_3p(afafn, 0);
        cout << "0.000 0.000 0.000\n";
        return 0;
    }
    if (imk-ima<=imb*2 && ima<imb && imk>=ima*2)
    {
        double afafn = (double)(imk)/2;
        cout_3p(afafn, 0);
        cout_3p(afafn, 0);
        cout << "0.000 0.000\n";
        return 0;
    }
    if (imk-ima<=imb)
    {
        double afafn = (double)(ima);
        cout_3p(afafn, 0);
        afafn = (double)(imk-ima);
        cout_3p(afafn, 0);
        cout << "0.000 0.000\n";
        return 0;
    }
    if (imk-ima-imb<=imc*3 && ima<imc && imb<imc && imk>=max(ima, imb)*3)
    {
        double afafn = (double)(imk)/3;
        cout_3p(afafn, 0);
        cout_3p(afafn, 0);
        cout_3p(afafn, 0);
        cout << "0.000\n";
        return 0;
    }
    if (imk-ima-imb<=imc*2 && imb<imc && imk-ima>=imb*2)
    {
        double afafn = (double)(ima);
        cout_3p(afafn, 0);
        afafn = (double)((imk-ima))/2;
        cout_3p(afafn, 0);
        cout_3p(afafn, 0);
        cout << "0.000\n";
        return 0;
    }
    if (imk-ima-imb<=imc)
    {
        double afafn = (double)(ima);
        cout_3p(afafn, 0);
        afafn = (double)(imb);
        cout_3p(afafn, 0);
        afafn = (double)(imk-ima-imb);
        cout_3p(afafn, 0);
        cout << "0.000\n";
        return 0;
    }
    if (imk-ima-imb-imc>imc)
    {
        if (imk-ima-imb-(imc*2)>imb)
        {
            double afafn = (double)(ima);
            cout_3p(afafn, 0);
            afafn = (double)(imk-ima)/3;
            cout_3p(afafn, 0);
            cout_3p(afafn, 0);
            cout_3p(afafn, 1);
            return 0;
        }
        else
        {
            double afafn = (double)(ima);
            cout_3p(afafn, 0);
            afafn = (double)(imb);
            cout_3p(afafn, 0);
            afafn = (double)(imk-ima-imb)/2;
            cout_3p(afafn, 0);
            cout_3p(afafn, 1);
            return 0;
        }
    }
    double afafn = (double)(ima);
    cout_3p(afafn, 0);
    afafn = (double)(imb);
    cout_3p(afafn, 0);
    afafn = (double)(imc);
    cout_3p(afafn, 0);
    afafn = (double)(imk-ima-imb-imc);
    cout_3p(afafn, 1);
    return 0;

}
