#include<iostream>
using namespace std;
int a[1000000],b[1000000];
int main()

{
    int n,br,br2,i;
    for(i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
   for(i=1;i<=n;i++)
    {
        if (a[i]==a[i+1]||a[i]==b[i+1]||b[i]==a[i+1]||b[i]==b[i+1]|&&a[i]+b[i]>=a[i+1]+b[i+1]) br++;
        else br=br;
    }
    for(i=1;i<=n;i++)
    {
        if (a[i]==a[i+1]||a[i]==b[i+1]||b[i]==a[i+1]||b[i]==b[i+1]|&&a[i]+b[i]>=a[i+1]+b[i+1]) br2++;
        else br2=br2;
    }
    if(br2>br) br=br2;
    cout<<br<<endl;
}
