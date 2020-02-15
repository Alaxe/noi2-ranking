#include <bits/stdc++.h>
using namespace std;
struct elem
{
    int t, len;
};
int w, k, n, m;
elem a[100001], b[100001];
map <string, int> mp;
long long sum;
string convert_to_string (int p)
{
    if (p==0) return "0";
    string rez="";
    while (p!=0)
    {
        int dig=p%10;
        rez=(char)(dig+'0')+rez;
        p/=10;
    }
    return rez;
}
void w2()
{
    sum=0;
    a[1].len=1;
    for (int i=2; i<=n; i++)
    {
        if (a[i].t==a[i-1].t) a[i].len=a[i-1].len+1;
        else a[i].len=1;
    }
    for (int i=1; i<n; i++)
    {
        if (a[i].len!=1 && a[i].len>=k && a[i+1].len==1)
        {
            mp[convert_to_string(a[i].t)]=a[i].len-k+1;
        }
    }
    if (a[n].len!=1 && a[n].len>=k)
    {
        mp[convert_to_string(a[n].t)]=a[n].len-k+1;
    }

    b[1].len=1;
    for (int i=2; i<=m; i++)
    {
        if (b[i].t==b[i-1].t) b[i].len=b[i-1].len+1;
        else b[i].len=1;
    }
    long long cnt=0;
    for (int i=1; i<m; i++)
    {
        if (b[i].len!=1 && b[i].len>=k && b[i+1].len==1)
        {
            cnt=b[i].len-k+1;
            sum+=cnt*mp[convert_to_string(b[i].t)];
        }
    }
    if (b[m].len!=1 && b[m].len>=k)
    {
        cnt=b[m].len-k+1;
        sum+=cnt*mp[convert_to_string(b[m].t)];
    }
    cout <<sum<<endl;

}
string form_row_w1(int beg, int en, elem mas[])
{
    string rez="";
    for (int i=beg; i<=en; i++)
    {
        rez+=convert_to_string(mas[i].t);
    }
    return rez;
}
void w1()
{
    sum=0;
    a[1].len=1;
    for (int i=2; i<=n; i++)
    {
        if (a[i].t>a[i-1].t) a[i].len=a[i-1].len+1;
        else a[i].len=1;
    }
    for (int i=1; i<=n; i++)
    {
        if (a[i].len!=1 && a[i].len>=k) mp[form_row_w1(i-k+1,i,a)]++;
    }
    b[1].len=1;
    for (int i=2; i<=m; i++)
    {
        if (b[i].t>b[i-1].t) b[i].len=b[i-1].len+1;
        else b[i].len=1;
    }
    for (int i=1; i<=m; i++)
    {
        if (b[i].len!=1 && b[i].len>=k)
        {
            sum+=mp[form_row_w1(i-k+1,i,b)];
        }
    }
    cout <<sum<<endl;
}
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >>w>>k;
    cin >>n;
    for (int i=1; i<=n; i++)
    {
        cin >>a[i].t;
    }
    cin >>m;
    for (int i=1; i<=m; i++)
    {
        cin >>b[i].t;
    }
    if (w==1) w1();
    else w2();
    return 0;
}
