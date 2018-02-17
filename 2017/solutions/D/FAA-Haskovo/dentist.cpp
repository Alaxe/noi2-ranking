#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

struct pacient
{
    int pristigane;
    int vremetraene_na_pregled;
};

bool cmp(pacient x,pacient y)
{
    if (y.pristigane<x.pristigane) return false;
    else return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    pacient a[10005];

    int i=0;
    while(cin>>a[i].pristigane>>a[i].vremetraene_na_pregled)
    {
        i++;
    }
    sort(a,a+i,cmp);

    int ost=0,vrkr[10005]={0};
    for (int j=0;j<i;j++)
    {
        if (vrkr[j-1]>a[j].pristigane) vrkr[j]=vrkr[j-1]+a[j].vremetraene_na_pregled;
        else vrkr[j]=a[j].pristigane+a[j].vremetraene_na_pregled;
        cout<<" "<<vrkr[j]<<"\n";
    }

    cout<<vrkr[i-1]-a[i-1].pristigane<<"\n";
    return 0;
}
/*
55 15
185 22
130 10
======
0 30
720 10
715 20
714 25
*/
