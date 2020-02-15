#include<iostream>
#define endl '\n'
using namespace std;
long long m[55][55],n,k;
long long rec(long long ch,long long pos,long long le,long long ri)
{
    if(ri>n || le<1) return 1;
    if(m[ch][pos]!=0 && ch!=1) return m[ch][pos];
    m[ch][pos]=rec(ch+1,le-1,le-1,ri)+rec(ch+1,ri+1,le,ri+1);
    return m[ch][pos];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    m[1][k]=1;
    cout<<rec(1,k,k-1,k+1)<<endl;
    return 0;
}
