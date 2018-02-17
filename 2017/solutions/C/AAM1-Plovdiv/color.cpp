#include<iostream>
using namespace std;
long long max1[11];
int main ()
{
long long a[11][10000],b,c,d,n;
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>b;
    for(int j=0;j<b;j++)
    {
        cin>>c;
        a[i][c]++;
        a[i][j]++;
        if(a[i][c]>max1[i])max1[i]=a[i][c];
        if(a[i][j]>max1[i])max1[i]=a[i][j];
    }
}
for(int i=0;i<n;i++)
{
    cout<<max1[i]<<endl;
}
return 0;
}
