#include<iostream>
using namespace std;
int main()
{
    int n, i, a[n], sh, v,b[n],br=0;
    cin>>n;
    for(i=1;i<=n;i++)
     {
        cin>>sh>>v;
        a=sh*2;
        b=v*2;
     }
    if(a[1]<a[2] && b[1]<a[1] || a[1]==a[2] && b[1]==b[2])br++;
    cout<<br<<endl;
    return 0;
}
