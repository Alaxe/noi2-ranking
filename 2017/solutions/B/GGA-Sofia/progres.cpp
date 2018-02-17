#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int maxx=0,minn=1000;
    for(int j=0;j<n;j++)
    {
        if(arr[j]>maxx) maxx=arr[j];
        if(arr[j]<minn) minn=arr[j];
    }
    int c=maxx-minn;
    int rr[c+1],mn=0;
    for(int j=1;j<c+1;j++)
    {
        rr[j]=0;
    }
    for(int y=0;y<n;y++)
    {
        for(int t=y+1;t<n;t++)
        {
            if((arr[y]-arr[t])<0) mn=arr[t]-arr[y]; rr[mn]=1;

        }
    }
    int red=0,posl=0;
    for(int d=1;d<c+1;d++)
    {
        if(rr[d]==1){
        for(int a=0;a<n-1;a++)
        {
            posl=arr[a];
            for(int b=a+1;b<n;b++)
            {
                if(arr[b]==posl+d||arr[b]==arr[a]+d) {
                        red++;
                        posl=arr[b];}
            }
        }}
    }
    cout<<red;
}

