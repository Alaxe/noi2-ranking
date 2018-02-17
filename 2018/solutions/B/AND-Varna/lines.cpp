#include<bits/stdc++.h>
using namespace std;
int n, i, j, k, nod, r1, r2, cnt, mx, curr[1024], ind;
bool aligned[1024][1024];
struct Point
{
    int x, y;
} points[1024];
bool cmp(Point a, Point b)
{
    if(a.x == b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(i=0; i<n; i++)cin>>points[i].x>>points[i].y;
    sort(points, points+n, cmp);
    //for(i=0;i<n;i++)cout<<points[i].x<<";"<<points[i].y<<" ";//!
    //cout<<"\n";//!
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(aligned[i][j])continue;
            cnt=2;
            ind=2;
            curr[0]=i;
            curr[1]=j;
            aligned[i][j] = true;
            aligned[j][i] = true;
            r1 = points[j].x - points[i].x;
            r2 = points[j].y - points[i].y;
            if(!r1)
            {
                for(k=j+1; k<n; k++)
                {
                    if(points[k].x==points[j].x)
                    {
                        for(int m=0; m<ind; m++)
                        {
                            aligned[curr[m]][k] = true;
                            aligned[k][curr[m]] = true;
                        }
                        cnt++;
                        curr[ind]=k;
                        ind++;
                    }
                }
            }
            else if(!r2)
            {
                for(k=j+1; k<n; k++)
                {
                    if(points[k].y==points[j].y)
                    {
                        for(int m=0; m<ind; m++)
                        {
                            aligned[curr[m]][k] = true;
                            aligned[k][curr[m]] = true;
                        }
                        cnt++;
                        curr[ind]=k;
                        ind++;
                    }
                }
            }
            else
            {
                nod=__gcd(r1, r2);
                r1/=nod;
                r2/=nod;
                for(k=j+1; k<n; k++)
                {
                    int nr1, nr2;
                    nr1 = points[k].x - points[j].x;
                    nr2 = points[k].y - points[j].y;
                    if(!nr1 || !nr2)continue;
                    nod = __gcd(nr1, nr2);
                    nr1/=nod;
                    nr2/=nod;
                    if(nr1 == r1 && nr2 == r2)
                    {
                        for(int m=0; m<ind; m++)
                        {
                            aligned[curr[m]][k] = true;
                            aligned[k][curr[m]] = true;
                        }
                        cnt++;
                        curr[ind]=k;
                        ind++;
                    }
                }
            }
            if(mx<cnt)mx=cnt;
           // for(int pch=0;pch<ind;pch++)cout<<curr[pch]<<" ";//!
           // cout<<"\n";//!
        }
    }
    cout<<mx<<"\n";
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
