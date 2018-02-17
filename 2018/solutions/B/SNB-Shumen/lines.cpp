#include<iostream>
#include<algorithm>
using namespace std;
struct cell
{
    int x,y;
    bool operator !=(cell a)
    {
        if(x!=a.x||y!=a.y)return true;
        return false;
    }
};
cell cl[1024];
int n;
bool check(cell a,cell b, cell c)
{
    if(a.x*b.y+b.x*c.y+c.x*a.y
       -(b.x*a.y+a.x*c.y+c.x*b.y)==0)return true;
    return false;
}
int line(cell a,cell b,int j)
{
    int i,br=2;
    cell p;
    for(i=j+1;i<n;i++)
    {
        p=cl[i];
        if(a!=p&&b!=p)
        {
            br+=check(a,b,p);
        }
    }
    return br;
}
int main()
{
    int i,j,tbr,br=0;
    cell b;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>b.x>>b.y;
        cl[i]=b;
    }
    for(i=0;i<n-2;i++)
    {
        for(j=i+1;j<n-1;j++)
        {
            tbr=line(cl[i],cl[j],j);
            if(br<tbr)br=tbr;
        }
    }
    cout<<br<<endl;
	return 0;
}
