#include<iostream>
using namespace std;
int main()
{
    long long n,brA=0,brB=0,brC=0,brD=0,i,r=0;
    cin>>n;
    char  b[n];
    cin>>b;
    for(i=0;i<n;i++)
    {
        if(b[i]=='a')
        {
            brA++;
        }
        if(b[i]=='b')
        {
            brB++;
        }
        if(b[i]=='c')
        {
            brC++;
        }
        if(b[i]=='d')
        {
            brD++;
        }
        if(brA+brB==brC+brD)
        {
            if(i+1>r)
            {
               r=i+1;
            }
        }
    }
    cout<<r;
    return 0;
}
