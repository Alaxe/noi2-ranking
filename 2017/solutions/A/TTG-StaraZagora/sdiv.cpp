#include<iostream>
#include<cstring>
using namespace std;

void Init(int *a, int n)
{
    for(int i=0;i<n;i++)a[i]=i;
}

bool nextComb(int *a, int n, int k)
{
    for(int i=k-1;i>=0;i--)
    {
        if(a[i]<n-k+i)///n-(k-1-i)
        {
            a[i]++;
            for(++i;i<k;i++)a[i]=a[i-1]+1;
            return true;
        }
    }
    return false;
}

int main()
{
    int a[10000];
    char s[16384];
	int n,m,len,p,c=0;
	cin>>s>>n>>m;
	len=strlen(s);
	for(int k=1;k<=len;k++)
	{
	    Init(a,k);
	    do
        {
            p=s[a[0]]-'0';
            for(int i=1;i<k;i++)
            {
                p*=10;
                p+=s[a[i]]-'0';
            }
            if(!(p%n))c++;
        }while(nextComb(a,len,k));
	}
	cout<<c%m<<endl;
	return 0;
}