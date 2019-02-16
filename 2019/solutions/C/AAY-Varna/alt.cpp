#include<bits/stdc++.h>
using namespace std;
unsigned long long endi=0;
int k,m,n;
unsigned long long r[50][50];
bool used[50][50];
void rec(int a,int br)
{
    if(used[a][br])
    {
        endi+=r[a][br];
        return;
    }
    if(br==n)
    {
        r[a][br]=1;
        used[a][br]=1;
        endi++;
        return;
    }
    if(a+k<m)rec(a+k,br+1);
    if(a-k>0)rec(a-k,br+1);
    r[a][br]=r[a+k][br+1]+r[a-k][br+1];
    used[a][br]=1;
}
int main()
{
    cin>>k>>m>>n;
    for(int i=1;i<m;i++)
    {
        rec(i,1);
    }
    cout<<endi<<endl;
}
