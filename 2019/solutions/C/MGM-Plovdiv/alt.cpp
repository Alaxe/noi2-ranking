#include <bits/stdc++.h>
using namespace std;
unsigned long long k, m, n, br=0;
void rec(int a, int len)
{
    if(a<=0) return;
    if(a>=m) return;
    if(len==1) {br++; return;}
    rec(a+k, len-1);
    rec(a-k, len-1);

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>k>>m>>n;
    for(int i=1; i<=m-1; i++)
    {
        rec(i+k, n-1);
        rec(i-k, n-1);
    }
    cout<<br<<endl;
    return 0;
}
