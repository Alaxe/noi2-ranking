#include<iostream>
using namespace std;
int main()
{
    int n,h,k,p,w=0,p1;
    cin>>n;
    k=n;
    int a[n];
    cin>>a[0]>>a[1];
    if(a[0]>a[1]) p=1;
    else
        {if(a[0]<a[1]) p=2;
        else {p=0; k--;}}

    for(int i=2; i<n; i++)
    {
        cin>>a[i];
        if(a[i]==a[i-1]) k--;
        else
        {if(a[i]>a[i-1]&&p==1) w++; else
        {if(a[i]<a[i-1]&&p==2) w++;}}
        p1=p;
        if(a[i-1]>a[i]) p=1;
        else
        {if(a[i-1]<a[i]) p=2;
        else p=0;}
        if(w>1) {k--;w=0; p=p1;}

    }
    cout<<k;
}
