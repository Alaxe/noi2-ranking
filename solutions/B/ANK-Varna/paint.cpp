#include<iostream>
#include<algorithm>
using namespace std;
bool flag;
struct str
{
    int l;
    int r;
    int u;
    int d;
    int s;
};
str b[11005];
bool cmp(str a,str b)
{
    return !(a.r>=b.r);
}
int search(int left,int right,int x)

{
    //cout<<right<<endl;
    if(x==b[left+(right-left)/2].r)
    return left+(right-left)/2+1;
    if(x<b[left].r) return 0;
    if(b[left+(right-left)/2].r<x&&b[left+(right-left)/2+1].r>x) return left+(right-left)/2+1;
    if(b[left+(right-left)/2].r>x) return search(left,right-(right-left)/2,x);
    else return search(left+(right-left)/2,right,x);
}
int main()
{
    int placeholder1,placeholder2;
    int n,m;
    cin>>n>>m;
    int a;
    cin>>a;
    for(int i=0; i<a; i++)
    {
        cin>>b[i].l>>b[i].u>>placeholder1>>placeholder2;
        b[i].s=placeholder1*placeholder2;
        b[i].r=b[i].l+placeholder1;
        b[i].d=b[i].u+placeholder2;

    }
    b[a].l=0;
    b[a].u=0;
    b[a].r=n;
    b[a].d=m;
    b[a].s=n*m;
    sort(b,b+a+1,cmp);
    int c,x,y,h;
    cin>>c;
    for(int i=0; i<c; i++)
    {
        cin>>x>>y;
        //h=1;
        h=search(0,a,x);
        for(int j=h; j<=a; j++)
        {
            if(x>b[j].l&&y<b[j].d&&y>b[j].u)
            {
                flag=1;
                if(j==0)
                {
                    cout<<b[0].s<<endl;
                    flag=1;
                }
                for(int g=j-1; g>=0; g--)
                {
                    if(b[g].l>b[j].l)
                    {
                        cout<<b[j].s-b[g].s<<endl;
                        flag=1;
                        break;

                    }
                    if(g==0) cout<<b[j].s<<endl;
                }
            }
            if(flag)
            {
                flag=0;
                break;
            }
        }
    }
    return 0;
}
/*
11 7
3
2 1 5 5
8 2 2 3
3 2 3 2
4
4 3
3 5
10 1
9 3
*/
