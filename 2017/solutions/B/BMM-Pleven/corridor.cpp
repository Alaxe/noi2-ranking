#include<iostream>
using namespace std;
int main()
{
    int n,w,h,x1,y1;
    int a[100000];
    cin>>w>>h;
    cin>>n;
    for(int i=0; i<=n; i++)
    {
        a[i]=0;
    }
    int pomosht=0;
    for(int i=0; i<n; i++ )
    {
        cin>>x1>>y1;
        for(pomosht; pomosht<=y1; pomosht++ )
        {

            if(a[y1]<x1)
            {
                a[y1]=x1;
            }
        }
        pomosht=y1;
    }
    int br=0;
    for(int i=0; i<h; i++)
    {
        br+=w-a[i];
    }
    br = br-w;
    cout<<br<<endl;
    return 0;
}
