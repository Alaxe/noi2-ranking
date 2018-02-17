#include <bits/stdc++.h>
using namespace std;
int d, m, d1, m1, d2, m2, d3, m3, i, daymax[14]= {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31}, t, t1=0, t2=0, t3=0;
int ron1[100000]= {0}, ron2[100000]= {0}, ron3[100000]= {0};
void prep();
int main()
{
    prep();

    if (t==t1 && t==t2 && t==t3)
    {
        cout << 21252 << endl;
        return 0;
    }
    else if (t>=t1 && t>=t2 && t>=t3)
    {
        for (i=t1; i<100000; i+=23) ron1[i]=1;
        for (i=t2; i<100000; i+=28) ron2[i]=1;
        for (i=t3; i<100000; i+=33) ron3[i]=1;
        for (i=t;  ; i++)
        {
            if (ron1[i]==1 && ron2[i]==1 && ron3[i]==1) break;
        }
        cout << i-t << endl;
    }
    else
    {
        for (i=t1; i>=t; i-=23) ron1[i]=1;
        for (i=t1; i<100000; i+=23) ron1[i]=1;
        for (i=t2; i>=t; i-=28) ron2[i]=1;
        for (i=t2; i<100000; i+=28) ron2[i]=1;
        for (i=t3; i>=t; i-=33) ron3[i]=1;
        for (i=t3; i<100000; i+=33) ron3[i]=1;
        for (i=t;  ; i++)
        {
            if (ron1[i]==1 && ron2[i]==1 && ron3[i]==1) break;
        }
        cout << i-t << endl;
    }
}
void prep()
{
    char k;

    cin >> d1;
    cin.get(k);
    cin >> m1;

    cin >> d2;
    cin.get(k);
    cin >> m2;

    cin >> d3;
    cin.get(k);
    cin >> m3;

    cin >> d;
    cin.get(k);
    cin >> m;

    for (i=1; i<m1; i++) t1+=daymax[i];
    t1+=d1;

    for (i=1; i<m2; i++) t2+=daymax[i];
    t2+=d2;

    for (i=1; i<m3; i++) t3+=daymax[i];
    t3+=d3;

    for (i=1; i<m; i++) t+=daymax[i];
    t+=d;

    return;
}
