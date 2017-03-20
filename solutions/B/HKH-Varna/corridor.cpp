#include<iostream>
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
long long int a[10000][10000];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int n,m;
    cin>>m>>n;
    long long int t;
    cin>>t;
    long long int x[t],y[t],l,q=1,X,Y;
    for(l=0; l<t; l++)
        {
            cin>>X>>Y;
            x[l]=Y;
            y[l]=X;
            if(l>=1)
                {
                    long long int x2=x[l-1],y2=y[l-1];
                    if(x2<x[l])
                        {
                            for(; x2<=x[l]; x2++)
                                a[x2][y2]=q;
                        }
                    else if(x2>x[l])
                        {
                            for(; x2>=x[l]; x2--)
                                a[x2][y2]=q;
                        }
                    ///**************///
                    else if(y2<y[l])
                        {
                            for(; y2<=y[l]; y2++)
                                a[x2][y2]=q;
                        }
                    else if(y2>y[l])
                        {
                            for(; y2>=y[l]; y2--)
                                a[x2][y2]=q;
                        }
                }
        }
    long long int i,j;
    for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
                {
                    cout<<a[i][j]<<" ";
                }
            cout<<"\n";
        }
    return 0;
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
