#include<iostream>
using namespace std;
unsigned long long s[270];
unsigned long long j[270];
int n,m;
int main()
{
    cin>>n>>m;
    for(int a=1;a<=m;a++)
    {
        for(int b=1; b<=n; b++)
        {
            if(b<a)
                s[b]=j[b];
            else if(b==a)
                s[b]=j[b]+1;
            else
                s[b]=j[b]+s[b-a];
        }
        for(int c=1; c<=n; c++)
        {
            j[c]=s[c];
        }
    }
    cout<<s[n]<<endl;
    return 0;
}
