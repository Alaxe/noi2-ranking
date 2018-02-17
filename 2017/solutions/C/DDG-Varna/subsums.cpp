#include <iostream>
using namespace std;

int a[1004],sum[100000]={0},b=0;

int main ()
{   int n,br=0,z,x=1,brx=0,c;
    bool t=false;
    cin>>n;
    z=n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for (int i=0;i<n;i++)
    {
        t=false;
        sum[i]=a[i];
        for (int j=0;j<i;j++)
        {
            if (sum[i]==sum[j])
            {
                sum[i]=0;
                t=true;
            }
        }
        br++;
        if (t==true)
        {
            z--;
            br--;
        }
    }
    for (int i=0;i<n-1;i++)
    {
        x=1;
        for (int h=i;h<n-1;h++)
        {
            for (int j=i+1;j<n-1;j++)
            {
                t=false;
                b=0;
                for (int k=0;k<x;k++)
                {
                    b=b+a[j+k];
                }
                sum[z]=a[i]+b;
                for (int k=0;k<z;k++)
                {
                    if (sum[z]==sum[k])
                    {
                        sum[z]=0;
                        t=true;
                    }
                }
                if (t==false){z++;br++;}
            }
            x++;
        }
    }
    cout<<br<<endl;
}
/**

5

1 -2 0 7 7

*/
