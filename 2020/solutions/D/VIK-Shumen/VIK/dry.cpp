#include <iostream>
using namespace std;

int main()
{
int n,u,v;
cin>>n>>u>>v;
int a[100];
int max=0;
int br=0;
int br1=0,br2=0,br3=0;
for(int i=0;i<n;i++)
{
    cin>>a[i];
    br3++;
    if(max<a[i])
    {
        max=a[i];
        br2=br2+br3;
    }
}
int max1=a[0];
for(int i=1;i<n;i++)
{
    if(max1<a[i-1])
    {
        max1=a[i-1];
        br1=0;
    }
    br1++;
    br2--;
    if(max==a[i-1])
    {
        br3=0;
        br2=0;
        for(int j=i;i<n;i++)
        {
            max=0;
            br3++;
            if(max<a[j])
            {
                max=a[j];
                br2=br2+br3;
            }
        }
    }
    if(a[i-1]<a[i])
    {
        if(max1<a[i])
        {
            br=br+u*v*br1*max1;
        }
        else
        {
            br=br+u*v*br1*a[i];
        }
    }
    if(a[i-1]>a[i])
    {
        if(max<a[i-1])
        {
            br=br+u*v*br2*max;
        }
        else
        {
            br=br+u*v*br2*a[i-1];
        }
    }
}
cout<<br<<endl;
    return 0;
}
