#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct point 
{
    int x,y,h;
};
point a[1024];
int br[1024],br1[1024],br2[1024];
bool cmp(point i,point j)
{
    if(i.h>j.h)return true;
    return false;
}
int main()
{
    int n,lamp=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].x>>a[i].y;
        if(a[i].x==0 && a[i].y==0)lamp=1;
    }
    for(int i=0;i<n;i++)
    {
        int h1=(a[i].x*a[i].x)+(a[i].y*a[i].y);
        a[i].h=h1;
    }
    sort(a,a+n,cmp);
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {  //cout<<"yeye"<<endl;
            int g,f;
            g=a[i].h;
            f=a[j].h;
            if(f!=0)
            {if(g%f==0)br[i]++;}
        }
    }
   
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            //cout<<"yeye"<<endl;
            if(abs(a[i].x)==abs(a[j].x))br1[i]++;
            if(abs(a[i].y)==abs(a[j].y))br2[i]++;
        }
    }
    int maxans=0,maxans1=0,maxans2=0;
    for(int i=0;i<n;i++)
    {
        if(br[i]>maxans)maxans=br[i];
        if(br1[i]>maxans1)maxans1=br1[i];
        if(br2[i]>maxans2)maxans2=br2[i];
    }
    if(lamp==1)
    maxans+=2;
    
    cout<<max(max(maxans,maxans1),maxans2)<<endl;
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