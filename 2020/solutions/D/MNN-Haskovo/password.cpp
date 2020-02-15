#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int brBuk[26];
string a;
int i, d, j, brZam, ind;
char z;
int Br_Posledovatelni(int i)
{
    int br = 0, j = i-1;
    char z = a[i];
    while (a[i]==z)
    {
        br++;
        i++;
    }
    while (a[j]==z)
    {
        br++;
        j--;
    }
    return br;
}
bool Can_Be_Placed(int i)
{
    if (brBuk[a[i]-'a']>d/2 || Br_Posledovatelni(i)>2)return 0;
    return 1;
}

void Fill()
{
    for (int i = 0; i < d; i++)brBuk[a[i]-'a']++;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> a;
    d=a.size();

    Fill();
    for (i = 0; i < d; i++)
    {
        ind = a[i]-'a';
        brZam = Br_Posledovatelni(i)/3;
        for (j = i+2; brZam > 0; j+=3)
        {
            brZam--;
            for (z = 'a'; z <= 'z'; z++)
            {
                a[j]=z;
                if (Can_Be_Placed(j))
                {
                    brBuk[ind]--;
                    brBuk[a[j]-'a']++;
                    break;
                }
            }
        }

    }

    for (i = 0; i < d; i++)
    {
        ind = a[i]-'a';
        if (brBuk[ind]>d/2)
        {
            for (z = 'a'; z <= 'z'; z++)
            {
                a[i]=z;
                if (Can_Be_Placed(i))
                {
                    brBuk[ind]--;
                    brBuk[a[i]-'a']++;
                    break;
                }
            }
        }
    }
    cout << a << endl;
    return 0;
}
// cooode
