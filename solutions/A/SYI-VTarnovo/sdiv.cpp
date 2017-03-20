#include<iostream>
using namespace std;

long long a1[100],a[100],u[50],n,m,n1,k,br;

void test(int i)
{
    long long sum=0;
	for(int kk=0;kk<i;kk++)
	sum=sum*10+a[kk];
	if(sum%n==0)br++;
	//cout<<sum<<endl;
}

 void comb(int i,int p)
{
    int j;
    if (i>k) test(i);
    else
        {
            for(j=p;j<n1;j++)
            {
                a[i]=a1[j];
                comb(i+1,j+1);
            }
        }
}

int main()
{
    string s;
    cin>>s;
    cin>>n>>m;
     n1=s.length();
    int j=0;
    while(j<n1)
	{
		a1[j]=s[j]-'0';
		j++;
	}
    for(int i=1;i<=n1;i++)
    {k=i;comb(1,0);}
    cout<<br%m<<endl;
}
