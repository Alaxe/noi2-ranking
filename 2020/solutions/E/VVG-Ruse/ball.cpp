#include<iostream>
using namespace std;
int main ()
{
    long long m,num,l,s,d;
    cin>>m>>num;
    
    if (num==0) {l=1; s=0; d=0;}
    if (num==1) {l=0; s=1; d=0;}
    if (num==2) {l=0; s=0; d=1;}
    
    for(int i=m; i>=1; i--)
    {
        if (i%2==0) swap(s,d);
        else swap(s,l);
    }
    
    if (l==1) cout<<"0\n";
    if(s==1) cout<<"1\n";
    if(d==1) cout<<"2\n";
    return 0;
}