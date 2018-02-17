#include <iostream>
using namespace std;
int d,n,a[1024],br=0;
void read()
{
    int i;
    cin>>n;
    for (i=0;i<n;i++)
        cin>>a[i];
}
void progres(int i,int d,int l)
{
    int j;
    if(i==n-1) return;
    for(j=i;j<n;j++)
    {
        if(j==n-1&&l==1)
        {
            br++;
            return;
        }
        if ((a[j]-a[i])==d) 
        progres(j,d,1);
                
    }
}
void solverino()
{
    int i,j,mael=0,miel=1001;
    for(i=0;i<n;i++)
    {
        if(a[i]>mael) mael=a[i];
        if(a[i]<miel) miel=a[i];
    }
    d=mael-miel;
    for(i=1;i<=d;i++)
    {
        for(j=0;j<n;j++)
        {
            progres(j,i,0);
        }
    }
    cout<<br<<endl;
}
int main()
{   
    read();
    if (n==2)
    {
        cout<<1<<endl;
        return 0;
    }
    solverino();
return 0;
}