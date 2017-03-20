#include<iostream>
using namespace std;
int main()
{
    int m, k, j, chisla, broi=0, sbor=0, min;
    cin>>m>>k;
    int b[199];
    for(int i=1; i<201; i++)
    {
        cin>>chisla;
        if(chisla%2==0) sbor+=chisla;
        if(m>=chisla) b[i]=m-chisla;
        if(m<=chisla) b[i]=chisla-m;
        broi++;
        if(sbor>k) break;
    }
    min=b[1];
    j=1;
    for(int f=1; f<=broi; f++)
    {
        if(b[f]<=min)
        {
            min=b[f];
            j=f;
        }
    }
    cout<<j<<" "<<sbor;
    return 0;
}
