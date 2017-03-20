#include<iostream>
#include<algorithm>
using namespace std;
struct rect
{
    int x, y, rx, ry;
};
rect r[11004];
int lice[11004];
bool cmp(rect a , rect b)
{
    return a.rx*a.ry<b.rx*b.ry;
}
bool bluskatLiSe(int x, int y, rect R)
{
    return (R.x<x && R.x+R.rx>x &&
       R.y<y && R.y+R.ry>y );
}
bool bl( rect a, rect b)
{
    return(a.x>b.x && a.x+a.rx<b.x+b.rx &&
           a.y>b.y && a.y+a.ry<b.y+b.ry);
}
int w,h, n;
int main(){
cin.tie(0);
ios::sync_with_stdio(false);
cin>>w>>h>>n;
r[0].x=0; r[0].y=0; r[0].rx=w; r[0].ry=h;
for(int i=1;i<=n;i++)
{
    cin>>r[i].x>>r[i].y>>r[i].rx>>r[i].ry;

}
sort(r,r+n+1, cmp);
//cout<<"aaaa\n";
for(int i=0;i<=n;i++)
{
    lice[i]=r[i].rx*r[i].ry;
 //   cout<<r[i].x<<" "<<r[i].y<<" "<<lice[i]<<endl;
}
for(int i=0;i<=n;i++)
{
    for(int j=i+1;j<=n;j++)
    {
        if(bl(r[i],r[j]))
        {
            lice[j]-=r[i].rx*r[i].ry;
            break;
        }
    }
}
//cout<<"aaaa\n";
/*for(int i=0;i<=n;i++)
{
    cout<<r[i].x<<" "<<r[i].y<<" "<<lice[i]<<endl;
}*/
int t;
cin>>t;
for(int i=0;i<t;i++)
{
    int x,y,index,minn=-1;
    cin>>x>>y;
    for(int i=0;i<=n;i++)
    {
        if(bluskatLiSe(x,y, r[i]))
        {
            if(lice[i]<minn || minn==-1 )
            {
                minn=lice[i];
            }
        }
    }
    cout<<minn<<endl;
}

return 0;
}
