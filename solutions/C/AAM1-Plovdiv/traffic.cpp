#include<iostream>
using namespace std;
char a[650][650];
long long n,m;
long long k1,k2;
long long min1=10000000;


void sth(char b[650][650],long long m1,long long m2,long long sum)
{
    char c;
    if(b[m1][m2]!='#')sum+=int(b[m1][m2])-64;

    if(m1==0 || m1==n-1){if(sum<min1)min1=sum;return;}
    if(m2==0 || m2==m-1){if(sum<min1)min1=sum;return;}


    if(b[m1+1][m2]!='*')
    {
        c=b[m1][m2];
        b[m1][m2]='*';
        sth(b,m1+1,m2,sum);
        b[m1][m2]=c;
    }
    if(b[m1][m2+1]!='*')
    {
        c=b[m1][m2];
        b[m1][m2]='*';
        sth(b,m1,m2+1,sum);
        b[m1][m2]=c;
    }
    if(b[m1-1][m2]!='*')
    {
        c=b[m1][m2];
        b[m1][m2]='*';
        sth(b,m1-1,m2,sum);
        b[m1][m2]=c;
    }
    if(b[m1][m2-1]!='*')
    {
        c=b[m1][m2];
        b[m1][m2]='*';
        sth(b,m1,m2-1,sum);
        b[m1][m2]=c;
    }

    return;
}


int main ()
{
 cin>>n>>m;
 for(int i=0;i<n;i++)
 for(int j=0;j<m;j++)
 {
     cin>>a[i][j];
     if(a[i][j]=='#'){k1=i;k2=j;}
 }

sth(a,k1,k2,0);
cout<<min1<<endl;
}


