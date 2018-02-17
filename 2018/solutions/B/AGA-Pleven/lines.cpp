#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>

#include<cmath>
using namespace std;
struct tochka{
    int x,y;
};
tochka a[1001];
double tang[1001][1001] , a1 , b1;
long long n,max1,maxg , cekx[202],ceky[202],maxtx,maxty , omax;
/*int fff(tochka f,tochka r)
{
    if (f.x>r.x) swap(f,r);
}
*/
int main () {
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (i!=j)
            {
                a1=a[j].y-a[i].y;
                b1=a[j].x-a[i].x;
                tang[i][j]=a1/b1;

            }
            else
            tang[i][j]=100000001;

        }

    }

    for (int i=1;i<=n;i++)
    {
        sort(tang[i]+1,tang[i]+n+1);
    }
  /*  for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
                cout<<tang[i][j]<<" ";
        }
        cout<<endl;
    }
    */

    for (int i=1;i<=n;i++)
    {
        for (int j=2;j<=n;j++)
        {
            if (tang[i][j]-tang[i][j-1]<0.00001) max1++;
            else
            {
                if (max1+1>maxg) maxg=max1+1;
                max1=0;
            }
        }
        max1=0;
    }
    maxg++;
    for (int i=1;i<=n;i++)
    {
        cekx[a[i].x+101]++;
        ceky[a[i].y+101]++;
    }
    for (int i=1;i<=202;i++)
    {
        if (cekx[i]>maxtx) maxtx=cekx[i];
        if (ceky[i]>maxty) maxty=ceky[i];
    }
    omax=max(maxtx,maxty);
    cout<<max(omax,maxg)<<endl;
return 0;
}
/*
6
0 0
2 1
-2 -1
-2 -2
6 3
-2 3
*/
