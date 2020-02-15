#include<iostream>
#define endl '\n'
using namespace std;
long long brm[100003];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n,m,a,i,j,b,k=0,c,ngs=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>c;brm[c]++;
        ngs=max(ngs,c);
    }
    for(i=0;i<=ngs;i++)
    {
        if(brm[i]){k+=brm[i];}
        brm[i]=k;
    }

    cin>>m;
    for(j=0;j<m;j++)
    {
        cin>>a>>b;
        if(a<=ngs&&b<=ngs)cout<<brm[b]-brm[a-1]<<endl;
        else if(a<=ngs&&b>ngs)cout<<brm[ngs]-brm[a-1]<<endl;
        else cout<<0<<endl;
    }

}
/*

6
9 1 3 10 3 4
3
1 4
9 12
15 20

*/
