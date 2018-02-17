#include<iostream>
#include<vector>
using namespace std;
struct cord
{
    float x;
    float y;
};
float dpy[111][1000];
float dpx[111][1000];
cord mas[1001];

const int all=100000,none=1000001;
int main()
{
    int n;
    int maxx=0,maxy=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>mas[i].x>>mas[i].y;
        if(mas[i].x>maxx)maxx=mas[i].x;
        if(mas[i].y>maxy)maxy=mas[i].y;
    }
    for(int j=0;j<=maxx;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(mas[i].x==0)
            {
                if(mas[i].y==j){dpx[j][i]=all;continue;}
                else dpx[j][i]=none;
                continue;
            }
            dpx[j][i]=(mas[i].y-j)/mas[i].x;
           //cout<<dpx[j][i]<<" ";
        }
        //cout<<endl;
    }
     for(int j=1;j<=maxy;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(mas[i].y==0)
            {
                if(mas[i].x==j){dpy[j][i]=all;continue;}
                else dpy[j][i]=none;
                continue;
            }

            dpy[j][i]=(mas[i].x-j)/mas[i].y;
            //cout<<dpy[j][i]<<" ";
        }
        //cout<<endl;
    }
    //cout<<endl;
    int ans=0;
    for(int c=0;c<=maxx;c++)
    {
        int high=0;
         for(int i=0;i<n;i++)
        {
            int br=0;
            for(int j=i;j>=0;j-- )
            {
                if(dpx[c][j]==all)br++;
                else if(dpx[c][i]==dpx[c][j])br++;
            }
            if(high<br)high=br;
        }
        if(ans<high)ans=high;
    }
    int ans2=0;
     for(int c=1;c<=maxy;c++)
    {
        int high=0;
         for(int i=0;i<n;i++)
        {
            int br=0;
            for(int j=i;j>=0;j--)
            {
                if(dpy[c][j]==all)br++;
                else if(dpy[c][i]==dpy[c][j])br++;


            }
            if(high<br)high=br;
        }
        if(ans2<high)ans2=high;
    }
    if(ans2>ans)cout<<ans2<<endl;
    else cout<<ans<<endl;
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
