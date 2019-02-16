#include<iostream>

using namespace std;

int k,m,n;
long long br;

void cik(int x,int brp)
{
    if(brp==n)
    {
        br++;
        return ;
    }
    if(x-k>0) cik(x-k,brp+1);
    if(x+k<m) cik(x+k,brp+1);
}

int main()
{
    cin>>k>>m>>n;
    for(int i=1;i<=m-1;i++)
    {
        cik(i,1);
    }
    cout<<br<<"\n";
    return 0;
}
