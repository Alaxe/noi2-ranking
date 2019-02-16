#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int k,m,n,br=0,tek,up,down,i;
    cin>>k>>m>>n;
    for (i=1;i<m;i++)
    {
        if(m-i-1) up=(m-i-1)/k;
        else up=0;
        if(i-1) down=(i-1)/k;
        else down=0;
        tek=(up+down)*(n-m/k);
        if(up&&down) tek*=2;
        br+=tek;
    }
    cout<<br<<endl;
    return 0;
}
