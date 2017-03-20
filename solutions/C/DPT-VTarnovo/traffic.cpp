#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int n,m,a[640][640],l1,ot;
int re(int r1,int r2)
{
	int q1=-1,q2=-1,q3=-1,q4=-1,mi;
	if(r1==0 || r2==0 || r1==n-1 || r2==m-1)return 0;
	if(a[r1+1][r2]>=1 && r1!=n-1 )
	{
		
		l1=1;
		q1+=re(r1+1,r2)+a[r1+1][r2]+1;
		
	}
	if(a[r1-1][r2]>=1 && r1!=0 )
	{
		
		l1=2;
	q2+=re(r1-1,r2)+a[r1-1][r2]+1;	
	}
	if(a[r1][r2+1]>=1 && r2!=m-1 )
	{
		
		l1=3;
	q3+=re(r1,r2+1)+a[r1][r2+1]+1;	
	}
	if(a[r1][r2-1]>=1 && r2!=0 )
	{
		
		l1=4;
		q4+=re(r1,r2-1)+a[r1][r2-1]+1;
	}
	mi=999999;
    if(q1!=-1)mi=q1;
    if(q2!=-1)mi=min(mi,q2);
    if(q3!=-1)mi=min(mi,q3);
    if(q4!=-1)mi=min(mi,q4);
    return mi;
}
int main()
{
	int s1,s2;
	char c;
	scanf("%d%d",&n,&m);
	for(int h=0;h<n;h++)
	   for(int f=0;f<m;f++)
	   {
	   	cin>>c;
	   	if(c>='A' && c<='Z')a[h][f]=c-'A'+1;
		else if(c=='*')a[h][f]=0;
		else if(c=='#')
		   {
		   	a[h][f]=-1;
		   	s1=h;s2=f;
		   }
	   }
    ot=re(s1,s2);
    if(ot==-1)printf("0\n");
	else printf("%d\n",ot);
    return 0;
}

