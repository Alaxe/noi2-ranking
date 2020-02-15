#include<iostream>
using namespace std;
int rez[100000];
bool b[100000];
int main()
{
int n;
cin>>n;
int a[100000],br0=0;
rez[0]=n-a[0];
for(int i=0;i<n;i++)
{
    cin>>a[i];
    if(a[i]==0&&i!=n-1)
    {
        rez[i]=n-br0;
        b[n-br0]=true;
        br0++;
    }
    else if(i!=n-1)
    {
        int c=a[i];
        int k=n-i-c;
        rez[i]=k;
        b[k]=true;
    }
}
int k=1;
while(b[k]==true)k++;
rez[n-1]=k;
cout<<rez[0];
for(int i=1;i<n;i++)
{
    cout<<" "<<rez[i];
}
cout<<endl;
return 0;
}
