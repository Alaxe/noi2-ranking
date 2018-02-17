#include<iostream>
#include<list>
using namespace std;
struct point
{
    int x1,y1,x2,y2,S;
    list <int> sp;
};
point sos[12000];
bool kudesife[12000];
bool used[12000];
int answers[12000];
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int S=0;
    list<int>::iterator it;
    int w,h,n;
    cin>>w>>h;
    S=w*h;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>sos[i].x1>>sos[i].y1>>w>>h;
        sos[i].x2=sos[i].x1+w;
        sos[i].y2=sos[i].y1+h;
        sos[i].S=w*h;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(sos[j].x1>sos[i].x1&&sos[j].y1>sos[i].y1&&sos[j].x1<sos[i].x2&&sos[j].y1<sos[i].y2)
            {
                sos[i].sp.push_back(j);
                used[j]=1;
                sos[i].S=sos[i].S-((sos[j].x2-sos[j].x1)*(sos[j].y2-sos[j].y1));
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(used[i]==0)S=S-(sos[i].x2-sos[i].x1)*(sos[i].y2-sos[i].y1);
    }
    int t,x,y;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        for(int o=1;o<=n;o++)
        {
            kudesife[o]=0;
        }
        cin>>x>>y;
        for(int i=1;i<=n;i++)
        {
            if(x>sos[i].x1&&y>sos[i].y1&&x<sos[i].x2&&y<sos[i].y2)
            {
                kudesife[i]=1;
            }
        }
        int flag=0;
        for(int o=1;o<=n;o++)
        {
            if(kudesife[o]==1)
            {
                flag=1;
                if(sos[o].sp.empty())answers[z]=sos[o].S;
                else
                {
                    int flag2=0;
                    for(it=sos[o].sp.begin();it!=sos[o].sp.end();it++)
                    {
                        if(kudesife[*it]==1)flag=1;
                    }
                    if(flag2==0)answers[z]=sos[o].S;
                }
            }
        }
        if(flag==0)answers[z]=S;
    }
    for(int i=1;i<=t;i++)
    {
        cout<<answers[i]<<'\n';
    }
    return 0;
}
