#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct patient
{
    int t, t1;
}a[720];
bool cmp(patient a, patient b)
{
    if(a.t<b.t)return true;
    else return false;
}
int size=0;
int k, n;
void Read()
{
    while(scanf("%d%d", &k, &n))
    {
        a[size].t=k; a[size].t1=n;
        size++;
    }
}
void Solve()
{
    sort(a, a+size, cmp);
    int sum=0;
    for(int i=0;i<size-1;i++)
    {
        if(a[i].t>=sum)sum=a[i].t;
        sum+=a[i].t1;
    }
    if(a[size-1].t>=sum)cout<<a[size-1].t1<<endl;
    else cout<<sum-a[size-1].t+a[size-1].t1<<endl;
}
int main()
{
    Read();
    Solve();
    return 0;
}
