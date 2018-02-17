#include<iostream>
using namespace std;
int main()
{
    long long n,m,tab[275][275],i,j,p,k,t,sum=0;
    cin>>n>>m;
    for(i=0;i<275;i++)
    for(j=0;j<275;j++)tab[i][j]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            sum=1;
            k=i;
            p=j;
            for(t=0;t<p;t++)
            {
                if(k-p+t>=1)
                {
                    sum+=tab[k-p+t][p-t];
                }
            }
            if(i>j)sum--;
            tab[i][j]=sum;
        }
    }
    cout<<tab[n][m]<<endl;
    return 0;
}