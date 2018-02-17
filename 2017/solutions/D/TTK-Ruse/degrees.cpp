#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
char a[160000];
int main()
{
    long long n=0,i,j,m,l=0,sum=1,f;
    cin>>a;
    m=strlen(a);
    f=1;
    for(i=0;i<m;i++)
    {
    for(j=0;j<f;j++)
    {
    sum=sum*2;
    }
    do
    {
    sum=sum/10;
    l++;
    }
    while(sum!=0);
    i=i+l-1;
    f++;
    n++;
    l=0;
    sum=1;
    }
    cout<<n<<endl;
    return 0;
}