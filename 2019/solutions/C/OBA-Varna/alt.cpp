#include<bits/stdc++.h>
using namespace std;
int k,m,n,i,br;
long long sum;

bool ways (int ind)
{
    br++;
    if (br==n) {sum++;br--;return 0;}

    if (ind+k<m) ways (ind+k);
    if (ind-k>0) ways (ind-k);

    br--;
    return 0;
}

int main()
{
    cin>>k>>m>>n;

    for (i=1;i<m;i++)
    {
        br=0;
        ways (i);
    }

    cout<<sum<<endl;
}
