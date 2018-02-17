#include<iostream>
using  namespace std;
int main ()
{
    long long n,l,otg,w,pr=0;
    cin>>n>>l;
    long iz[10];
    long long tab[10-l];
    for (w=0; w<l; w++) cin>>iz[w];
    for (w=l; w<10; w++) iz[w]=11;
    for (w=0; w<10-l; w++)
    {
        if (pr==iz[0] or pr==iz[1] or pr==iz[2] or pr==iz[3] or pr==iz[4] or pr==iz[5] or pr==iz[6] or pr==iz[7] or pr==iz[8] or pr==iz[9] )
        {
            pr++;
            if (pr==iz[0] or pr==iz[1] or pr==iz[2] or pr==iz[3] or pr==iz[4] or pr==iz[5] or pr==iz[6] or pr==iz[7] or pr==iz[8] or pr==iz[9] )
            {
                pr++;
                if (pr==iz[0] or pr==iz[1] or pr==iz[2] or pr==iz[3] or pr==iz[4] or pr==iz[5] or pr==iz[6] or pr==iz[7] or pr==iz[8] or pr==iz[9] )
                {
                    pr++;
                }
            }
        }
        tab[w]=pr;
        pr++;
    }
    if (n<10-l) cout<<tab[n];
    else
    {
        if (n>=(10-l)*10)
        {
            otg=tab[n/((10-l)*10)]*100;
            otg=(tab[(n%((10-l)*10))-1]*10)+otg;
            otg=tab[n%(10-l)]+otg;
           cout<<otg;
        }
        else
        {

            otg=tab[n/(10-l)]*10;
            otg=tab[n%(10-l)]+otg;

            cout<<otg;
        }
    }

    return 0;
}
