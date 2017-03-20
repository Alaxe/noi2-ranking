#include<iostream>
using namespace std;
int main()
{
    int w,h,n,x1,y1,x2,y2;
    cin>>w>>h>>n;
    int m[h];
    for(int i=0;i<h;i++)
    {
        m[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        cin>>x1>>y1;
        if(i!=0 and y1!=y2)
        {
            for(int j=min(y1,y2);j<max(y1,y2);j++)
            {
                if(m[j]<x1) m[j]=x1;
            }
        }
        x2=x1;
        y2=y1;
    }
    long long s=0;
    for(int i=0;i<h;i++)
    {
        s+=w-m[i];
    }
    cout<<s;
    return 0;
}
