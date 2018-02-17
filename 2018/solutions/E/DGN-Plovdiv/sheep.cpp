# include <bits/stdc++.h>
using namespace std;
int main ()
{
    long long n, cifri, a1, a2, a3, br=0, i=0, ed, cpy, flag=0;
    cin>>n;
    cin>>cifri;
    if (cifri==3)
    {
        cin>>a1>>a2>>a3;
    }
    if (cifri==2)
    {
        cin>>a1>>a2;
        a3=-1;
    }
    if (cifri==1)
    {
        cin>>a1;
        a2=-1;
        a3=-1;
    }

    while (br!=n)
    {
        i++;
        cpy=i;
        flag=1;
        while (i!=0)
        {
            ed=i%10;
            i=i/10;
            if (ed==a1 || ed==a2 || ed==a3)flag=0;
        }
        if(flag==1)br++;
        i=cpy;
        if (br==n)break;
    }
    cout<<cpy<<endl;
    return 0;
}
