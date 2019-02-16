#include<iostream>
using namespace std;
int minatm=100001;
bool a[16000][16000];
void fun(int x,int y,int atm,bool wh,bool r,bool l)
{
    if(atm>minatm)return;
    else
    {
        if(y==0)
        {
            if(atm<minatm)minatm=atm;
        }else
        {
            if(a[x][y-1]==true)
            {
                if(wh==false)
                {
                    atm++;
                    fun(x-1,y,atm,true,true,false);
                    fun(x+1,y,atm,true,false,true);
                }else
                {
                    if(l==true)fun(x+1,y,atm,true,false,true);
                    if(r==true)fun(x-1,y,atm,true,true,false);
                }
            }else fun(x,y-1,atm,false,false,false);
        }
    }
}
int main ()
{
    ios::sync_with_stdio(true);
    cin.tie(NULL);
    int n;
    int x,y,l;
    int maxy=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y>>l;
        if(y>maxy)maxy=y;
        for(int j=x;j<x+l;j++)
            a[j][y]=true;
    }
    int t,start;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        minatm=100001;
        cin>>start;
        fun(start,maxy+1,0,false,false,false);
        cout<<minatm<<" ";
    }
    cout<<endl;
    return 0;
}
