# include<iostream>
#include<algorithm>
using namespace std;
int n;
struct bolni
{
    int ta;
    int tn;
};
bolni pac[720];
bool cmp(bolni a,bolni b)
{
    if(a.ta<b.ta) return 1;
    return 0;
}
void Read()
{
    int i=0;
    int a,b;
    while(cin>>a>>b)
    {
        pac[i].ta=a;
        pac[i].tn=b;
        i++;
    }
    sort(pac,pac+i,cmp);
    n=i;
}
void Solve()
{
    int ov=0;
    for(int i=1;i<n;i++)
    {
        if(pac[i-1].ta+pac[i-1].tn+ov<=pac[i].ta)ov=0;
        else
        {
            ov=pac[i-1].ta-pac[i].ta+pac[i-1].tn+ov;
        }
    }
    cout<<ov+pac[n-1].tn<<endl;
}
int main()
{
    Read();
    Solve();
    return 0;
}

