#include <iostream>
using namespace std;
int k,m;
int rec (int a,int n)
{
    if (a<=0 or a>=m)return 0;
    if (n==1)return 1;
    return rec(a+k,n-1)+rec(a-k,n-1);
}
int main ()
{
    int br=0;
    int n;
    int p;
    cin>>k>>m>>n;
    for (int i=1;i<m;i++)
    {
        p=rec(i,n);
        if(p!=0)br=br+p;
        else break;

    }
    cout<<br<<endl;
    return 0;
}
