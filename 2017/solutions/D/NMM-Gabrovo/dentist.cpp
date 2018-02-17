#include<iostream>
#include<algorithm>
using namespace std;

struct p
{
    int t1;
    int t2;
};

bool cmp(p x, p y)
{
    if(x.t1<y.t1) return true;

    return false;
}

p pt[750];

int main()
{
    int n=0;

    while(cin)
    {
        cin>>pt[n].t1>>pt[n].t2;
        n++;
    }

    n--;

    sort(pt, pt+n, cmp);

    /* for(int i=0;i<n;i++)
    {
        cout<<pt[i].t1<<" "<<pt[i].t2<<endl;
    } */

    int t=pt[0].t1+pt[0].t2;

    for(int i=1;i<n;i++)
    {
        if(pt[i].t1>t) t=pt[i].t1;

        t+=pt[i].t2;
    }

    int ans=t-pt[n-1].t1;

    cout<<ans<<endl;

    //cout<<pt[n-1].t1<<" "<<t<<" "<<t-pt[n-1].t1<<endl;

    return 0;
}
// 0 30 720 10 715 20 714 25
