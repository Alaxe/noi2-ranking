#include <bits/stdc++.h>
using namespace std;
int m[100000],a[100000],b[100000]={0};
bool pr[100000]={0};
void cm(int n)
{
    while(n>1)
    {
        b[n-1]++;
        n--;
    }
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,ng,j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>m[i];
    }
    a[0]=n-m[0];
    cm(a[0]);
    pr[a[0]]=true;
    for(i=1;i<n;i++)
    {
        j=0;
        while(true)
        {
            if(false==pr[(n-m[i]-j)])
            {
                break;
            }
            j++;
        }
        a[i]=(n-m[i])-b[n-m[i]-j];
        j=0;
        while(true)
        {
            if(false==pr[a[i]-j])
            {
                break;
            }
            j++;
        }
        a[i]=a[i]-j;
        cm(a[i]);
        pr[a[i]]=true;
    }
    for(i=0;i<n;i++)
    {
        if(i!=0)
        {
            cout<<" ";
        }
        cout<<a[i];
    }
    return 0;
}
