#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct otsechka
{
    long long x1,x2,y1,y2;
};
bool cmp(otsechka a, otsechka b)
{
    return a.x1>b.x1;
}
long long nam[100005];
int main()
{
    otsechka a[100005];
    long long n,m;
    cin>>n>>m;
    long long k;
    cin>>k;
    long long p1,p2,q1,q2;
    cin>>p1>>q1;
    long long j=1;
    for(long long i=2;i<=k;i++)
    {
        cin>>p2>>q2;
        if(p1==p2)
            {
                a[j].x1=p1;
                a[j].y1=q1;
                a[j].x2=p2;
                a[j].y2=q2;
                if(q1>q2)swap(a[j].y1,a[j].y2);
                j++;
            }

        p1=p2;
        q1=q2;
    }
    j--;
    long long ans=0;
    sort(a+1,a+j+1,cmp);
        for(long long i=1;i<=j;i++)
        {
            if(nam[i]==a[i].y2-a[i].y1)continue;
            ans=ans+((a[i].y2-a[i].y1)-nam[i])*(n-a[i].x1);

            for(long long l=i+1;l<=j;l++)
            {
                if(a[i].y2<a[l].y1 or a[i].y1>a[l].y2)continue;
                else if(a[i].y1>=a[l].y1 and a[i].y2<=a[l].y2)
                nam[l]=nam[l]+((a[i].y2-a[i].y1)-nam[i]);
                else if(a[i].y1<=a[l].y1 and a[i].y2>=a[l].y2)
                {nam[l]=(a[l].y2-a[l].y1);}
                else if(a[i].y2<a[l].y2)
                {
                    nam[l]=nam[l]+((a[i].y2-a[l].y1)-nam[i]);
                }
                else nam[l]=nam[l]+((a[l].y2-a[i].y1)-nam[i]);
                if(nam[l]>(a[l].y2-a[l].y1))nam[l]=(a[l].y2-a[l].y1);
            }
        }
        cout<<ans<<endl;
    return 0;
}
