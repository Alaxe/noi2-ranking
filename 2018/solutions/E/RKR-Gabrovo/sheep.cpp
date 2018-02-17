#include<iostream>
using namespace std;
int main()
{
    int n,l,i,j,x,a,b,c,maxn,y,z;
    cin>>n>>l;
    for (i=1;i<=l;i++)
    {
        cin>>x;
        if (i==1) a=x;
        if (i==2) b=x;
        if (i==3) c=x;
    }

    for (j=1;j++;)
    {
        if (j<=9 && j>=0)
        {
            if (j!=a && j!=b && j!=c) {maxn=j;n--;}
        }
        if (j<=99 && j>=10)
        {
            y=j%10;
            z=j%10;
            if (y!=a && z!=a && y!=b && z!=b && y!=c && z!=c) {maxn=j;n--;}
        }
        if (n==0) break;
        y=0;
        z=0;
    }
    if (l==1) maxn=maxn+10;
    if (l==3) maxn=maxn+9;
    cout<<maxn<<endl;
    return 0;
}
