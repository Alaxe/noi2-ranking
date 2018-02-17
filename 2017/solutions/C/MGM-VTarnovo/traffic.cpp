#include <cstdio>
#include <iostream>

using namespace std;


void oc(int x,int y);
int r,c;
int t=0;
char tp[640][640];
int main()
{
	scanf("%d %d",&r,&c);
	int px,py;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>tp[i][j];
			if(tp[i][j]=='#')
			{
				px=i;
				py=j;
			}
		}
	}
	oc(px,py);
	printf("%d",t);
	
}
void oc(int x,int y)
{
	if(x<0||x>r||y<0||y>c)
	{
		return;
	}
	if(tp[x][y]=='*')
	{
		return;
	}
	t+=tp[x][y]-'A'+1;
	oc(x+1,y);
	oc(x-1,y);
	oc(x,y+1);
	oc(x,y-1);
}
