#include<bits/stdc++.h>
using namespace std;
int k,m,n;
int pp(int a1,int an,int n,int i)
{
    if(n<1 or a1<1 or a1>an)
    {
        return 0;
    }


    return 1+pp(a1-i,an,n-1,i)+pp(a1+i,an,n-1,i);
}

int main ()
{
ios_base::sync_with_stdio(0);
cin>>k>>m>>n;
int s=0;
for(int i=1;i<=k;++i)
{
    int k1=(m-i+1)/k;
    int p=pp(i,i+(k1-1)*k,n-2,i);

    s+=k1*p;
}
cout<<s<<endl;

    return 0;
}
