#include<iostream>
#define endl '\n'
using namespace std;
long long n,k,m[100][100][100];

long long rec(long long le,long long r,long long c)
{
    if(le<1||r>n||c>n)return 0;
    if(le==1&&r==n&&c==n){return 1;}
    if(m[le][r][c])return m[le][r][c];
    m[le][r][c]=rec(le-1,r,c+1)+rec(le,r+1,c+1);
    return m[le][r][c];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;

    cout<<rec(k,k,1)<<endl;


}
