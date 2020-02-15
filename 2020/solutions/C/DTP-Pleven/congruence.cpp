#include<iostream>
#include<string>
#include<cstdio>
#define INF 27
using namespace std;
string s;
long long i,j,k,d,n,m,p,q,a[30],max1;
bool b[30];
char c;
int main()
{
    cin>>s;
    d=s.size()-1;
    for(i=0;i<=d;i++)
    {
        b[s[i]-'A'+1]=true;
    }
    for(i=1;i<=27;i++)
    {
        for(j=i-1;j>=1;j--)
        {
            if(b[j])
                a[i]++;
        }
        if(a[i]>max1)max1=a[i];
        //cout<<a[i]<<" "<<i<<endl;
    }
    k=26-max1;
    for(i=0;i<=d;i++)
    {
        p=s[i]-'A'+1;
        c = char(a[p]+'A');
        printf("%c",c);
    }
    printf("\n");
    for(i=0;i<=d;i++)
    {
        p=s[i]-'A'+1;
        c = char(a[p]+'A'+k);
        printf("%c",c);
    }
    return 0;
}
