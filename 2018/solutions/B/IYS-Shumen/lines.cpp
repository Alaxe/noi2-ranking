#include <bits/stdc++.h>
#define MAX 150
using namespace std;
struct point 
{
    int x,y;
};
int GCD(int a,int b)
{
    if(a<b)swap(a,b);
    while(b!=0)
    {
        a%=b;
        swap(a,b);
    }
    return a;
}
vector<point>v;
int arr[512][512];
int main()
{
    int i,j,n,a,b;
    int maxx=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        
        point p;
        p.x=a;
        p.y=b;
        v.push_back(p);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            int ta,tb;
            ta=v[i].x-v[j].x;
            tb=v[i].y-v[j].y;
            int t;
            t=GCD(ta,tb);
            ta/=t;
            tb/=t;
            //pair<int,int>pp;
            //pp.first=ta;
           // pp.second=tb;
            arr[ta+MAX][tb+MAX]++;
            //mapche[pp]++;
            int h=arr[ta+MAX][tb+MAX];
            if(h>maxx)
            {
                //cout<<pp.first<<" "<<pp.second<<" "<<h<<endl;
                maxx=h;
            }
        }
        memset(arr,0,sizeof(arr));
        //mapche.clear();
    }
    cout<<maxx+1<<endl;
    return 0;
}