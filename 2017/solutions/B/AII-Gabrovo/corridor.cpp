# include<iostream>
# include<cmath>
using namespace std;

struct point
{
    int x,y;
};

point p[100001];
point k;
int main()
{
    int w,h;
    cin>>w>>h;
    int n;
    cin>>n;
    cin>>p[0].x>>p[0].y;

    long long ans=0;
    for(int i=1; i<n; i++)
    {
        cin>>p[i].x>>p[i].y;
        if(p[i].y==k.y)
        {
            if(p[i].x>k.x) k.x=p[i].x;
        }
        else
            if(p[i].y>k.y)
            {
                ans+=(long long)(p[i].y-k.y)*p[i].x;
               // cout<<ans<<" "<<k.x<<" "<<k.y<<" "<<p[i].x<<" "<<p[i].y<<endl;
                k.x=p[i].x;
                k.y=p[i].y;

            }

    }
    cout<<(long long)w*h-ans<<endl;
/*
10 8
14
6 0
6 6
7 6
7 1
8 1
8 2
9 2
9 3
8 3
8 4
9 4
9 5
8 5
8 8
*/
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
