#include<iostream>
using namespace std;
int pd[50];
unsigned long long sm=1;
int chk[50];
int n, k;
void f(int n)
{
    int p=2, br=0;
    while(n!=1)
    {
        while(n%p==0)
        {
            n/=p;
            br++;
        }
        if(br>pd[p]) pd[p]=br;
        br=0;
        p++;
    }
}
bool check()
{
    int b;
    bool ok=true;
    for(int i=2;i<=45;i++)
    {
        b=chk[i]*k;
        if(b<pd[i] && pd[i]!=0)
        {
            chk[i]++;
            sm*=i;
            ok=false;
        }
    }
    if(ok==false) return false;
    else return true;
}
int main()
{
    cin>>n>>k;
    int a;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        f(a);
    }
    for(int i=2;i<=45;i++)
        if(pd[i]>0)
        {
            chk[i]=1;
            sm*=i;
        }
    while(true)
    {
        if(check()==true)
        {
            cout<<sm<<endl;
            return 0;
        }
    }
    return 0;
}
/**
4 3
3 4 5 7
*/

