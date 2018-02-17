#include<iostream>
using namespace std;
int a[128][128];
int b[10001], br=0;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            char ch1, ch2;
            cin>>ch1>>ch2;
            if(ch1>='2' && ch1<='9')
                a[i][j]=ch1-'0';
            else if(ch1=='A')
                a[i][j]=1;
            else if(ch1=='T')
                a[i][j]=10;
            else if(ch1=='J')
                a[i][j]=11;
            else if(ch1=='Q')
                a[i][j]=12;
            else
                a[i][j]=13;
        }
    }
    if(n==1)
    {
        cout<<a[0][0]<<endl;
        return 0;
    }
    int max0=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<n;j++)
        {
            b[br]=a[i][j];
            br++;
        }
    }
    int x=0, y=n*n-1;
    for(int i=0;i<2*n+2;i++)
        {
            if(x%n==n-1) x=x+n;
            else if(x>=n*n-n) x=x+1;
            else if(b[x+1]>b[x+n]) x=x+1;
            else x=x+n;
            if(x==n*n-1)
            {
                max0+=b[0]+b[n*n-1];
                break;
            }
            else
                max0+=b[x];
        }
    int max1=0;
    for(int i=0;i<2*n+2;i++)
        {
            if(b[y-1]>b[y-n]) y=y-1;
            else y=y-n;
            if(y==0)
            {
                max1+=b[0]+b[n*n-1];
                break;
            }
            else
                max1+=b[y];
        }
    cout<<max(max1, max0)<<endl;
    return 0;
}
