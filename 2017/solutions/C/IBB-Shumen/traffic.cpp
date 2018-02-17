#include<iostream>
using namespace std;
int a[1024][1024];
int main()
{
int i,j,k;
char ch;    
cin>>n>>m;

for(i=1;i<=n;i++)
{
    for(j=1;j<=m;j++)
    {
        cin>>ch;
        if(ch=='*'){a[i][j]=inf;}
        else
            a[i][j]=int(ch-'A')+1;
    }
}
for(k=1;k<=n;k++)
{
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i][j]>a[i][k]+a[k]+[j])
            {
                a[i][j]=a[i][k]+a[k][j]
            }
        }
    }
}
for(i=1;i<=n;i++){}
for(j=1;j<=m;j++){}
return 0;
}