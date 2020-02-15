#include <iostream>
#include <string>
using namespace std;
int main()
{

int n,b[100000],a[100000],br=0,ind;
cin>>n;
int asd[100000][2]={0,};
for(int i=0;i<n;i++)
{
    cin>>b[i];
    asd[i][1]=i;
}
for(int i=0;i<n;i++)
{
    ind=n-b[i];
    for(int j=ind;j>0;j--)
        if(asd[j][2]==0){a[i]=asd[j][1];asd[i][2]=1;break;}
}
for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
cout<<endl;
return 0;
}
