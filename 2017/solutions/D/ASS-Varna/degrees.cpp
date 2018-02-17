#include<bits/stdc++.h>
using namespace std;
int step(int n)
{
    unsigned long long sum=1,i;
    for (i=1; i<=n; i++)
    {
        sum*=2;
    }
    i=0;
    while(sum>0)
    {
        sum/=10;
        i++;
    }
return i;
}
int main()
{
    int f=1,i,sum=0;
    string t;
    cin>>t;
    for (i=1;;i++)
    {
        f=step(i);
        sum+=f;
        if (sum==t.size()) {cout<<i<<endl;break;}
    }

        return 0;
}
/**
2
--
1
--
2481632
-------------
5
--------------
248163264128256512
-----------------------
9
*/
