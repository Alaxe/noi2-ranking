#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<stack>
#include<string>

using namespace std;

int br = 0,brNow;

int save[100][100];

void recursion(int now,int deep,int k,int m,int n)
{
    if(n == deep)
    {
        br++;
        brNow++;
        return;
    }
    if(now + k < m)
    {
        recursion(now + k,deep + 1,k,m,n);
    }
    if(now - k > 0)
    {
        recursion(now - k,deep + 1,k,m,n);
    }
    return;
}

int main()
{
    int k,m,n;
    cin>>k>>m>>n;
    for(int i = 1;i <= m / 2;i++)
    {
        brNow = 0;
        recursion(i,1,k,m,n);
    }
    br *= 2;
    if(m % 2 == 0)
    {
        br -= brNow;
    }
    cout<<br<<endl;
}
