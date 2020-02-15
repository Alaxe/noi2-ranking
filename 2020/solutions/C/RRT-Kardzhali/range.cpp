#include<iostream>
using namespace std;
int a[100001];
int br[100001];
int ch1, ch2, g=0, p1, p2;
int vuvedi(int n)
{
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
}
int sorter(int n)
{
    int x, i;
    bool right=false;
    while(right!=true)
    {
        right=true;
        for(i=0;i<n-1;i++)
        {
            if(a[i]>a[i+1])
            {
                right=false;
                x=a[i];
                a[i]=a[i+1];
                a[i+1]=x;
            }
        }
    }
}
int checker(int x, int c1, int c2)
{
    if((a[x-1]<c1)&&(a[x-1]<c2))
    {
        p1=0;
        p2=-1;
    }
    else
    {
        for(int i=0;i<x;i++)
        {
            if(a[i]>=c1)
            {
                p1=i;
                break;
            }
        }
    for(int i=p1;i<x;i++)
    {
        if(a[x-1]<c2)
        {
            p2=x-1;
            break;
        }
        if(a[i]>c2)
        {
            p2=i-1;
            break;
        }
        if(a[i]==c2)
        {
            p2=i;
            break;
        }
    }
    }
}
int izvedi()
{
    for(int i=0;i<g;i++)
    {
        cout<<br[i]<<endl;
    }
}
int main()
{
    int n, m, x=1;;
    cin>>n;
    vuvedi(n);
    sorter(n);
    cin>>m;
    while(x<=m)
    {
        cin>>ch1>>ch2;
        checker(n, ch1, ch2);
        br[g]=p2-p1+1;
        g++;
        x++;
    }
    izvedi();
    return 0;
}
