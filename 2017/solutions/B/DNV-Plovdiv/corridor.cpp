#include<bits/stdc++.h>
#include<cstdio>
#define MAXN 100005
using namespace std;
long long n,x[MAXN],y[MAXN],d;
unsigned long long w,he,ans;
struct masiv
{
    long long up,down,h;
};
masiv arr[MAXN];
bool cmp(masiv a,masiv b)
{
    if(a.up!=b.up)return a.up<b.up;
    if(a.down!=b.down)return a.down<b.down;
    return a.h<b.h;
}
int main()
{
    scanf("%lld%lld%lld",&w,&he,&n);
    scanf("%lld%lld",&x[0],&y[0]);
    for(int i=1;i<n;i++)
    {
        scanf("%lld%lld",&x[i],&y[i]);
        if(y[i]!=y[i-1])
        {
            if(y[i-1]<y[i])
            {
                arr[d].up=min(y[i],y[i-1]);
                arr[d].down=max(y[i],y[i-1]);
                arr[d].h=x[i];
                d++;
            }
        }
    }
    sort(arr,arr+d,cmp);
    long long last=0;
    for(int i=1;i<d;i++)
    {
        //cout<<"UP="<<arr[i].up<<" DOWN="<<arr[i].down<<" H="<<arr[i].h<<" last="<<last<<endl;
        //cout<<"UP="<<arr[last].up<<" DOWN="<<arr[last].down<<" H="<<arr[last].h<<" last="<<last<<endl;
        if(arr[i].down<=arr[last].up)
        {
            arr[i].h=0;
        }
        else
        if(arr[i].up<arr[last].down)
        {
            if(arr[i].down<=arr[last].down)
            {
                    if(arr[i].h<arr[last].h)arr[i].h=0;
                    else
                    {
                            arr[last].down=arr[i].up;
                            last=i;
                    }
            }
            else
            {
                if(arr[i].h<arr[last].h)
                {
                    arr[i].up=arr[last].down;
                }
                else
                {
                    arr[last].down=arr[i].up;
                }
                last=i;
            }
        }
        else
        {
            last=i;
        }
    }
    for(int i=0;i<d;i++)
    {
        //cout<<"UP="<<arr[i].up<<" DOWN="<<arr[i].down<<" H="<<arr[i].h<<endl;
        ans+=(arr[i].down-arr[i].up)*arr[i].h;
        //cout<<ans<<endl;
    }
    printf("%lld\n",(w*he-ans));
    return 0;
}
/*
15 10
16
6 0
6 2
11 2
11 6
8 6
8 4
9 4
9 5
10 5
10 3
6 3
6 7
12 7
12 8
9 8
9 10
*/
