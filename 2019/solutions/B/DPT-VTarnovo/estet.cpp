
#include <iostream>
#include <stdio.h>
using namespace std;
int n,lenght;
int a[100111],p[100111], br[100111], ans;

void init()
{
	scanf("%d",&n);
	for(int c=0;c<n;c++)scanf("%d",&a[c]);
	return;
}


int BinSearch2(int x)
{
	int l=0,r=lenght ,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(p[mid]>x)r=mid - 1;
		else if(p[mid]<x)l=mid + 1;
		else return mid;
	}
	return r;
}

void dp1()
{
    int rf;
	lenght=1;
	fill(p, p + n + 2, 1000000);
	for(int c=0;c<n;c++)
	{
		if(a[c]<p[0])p[0]=a[c], rf = 1;
		else if(a[c]>p[lenght-1])rf = lenght + 1, p[lenght++]=a[c];
		else
        {
            rf = BinSearch2(a[c]);
            p[rf]=a[c];
            rf++;


        }
		br[c] = rf;
	}
	return;
}

void dp2()
{
    int rf;
	lenght=1;
	fill(p,p + n + 2, 1000000);
	for(int c=n - 1;c>=0;c--)
	{
		if(a[c]<p[0])p[0]=a[c], rf = 1;
		else if(a[c]>p[lenght-1])rf = lenght + 1, p[lenght++]=a[c];
		else
        {
            rf = BinSearch2(a[c]);
            p[rf]=a[c];
            rf++;
        }
		ans = max(ans, br[c] + rf - 1 );

	}
	return;
}

void print()
{
	printf("%d\n",ans);
	return;
}

int main()
{
	init();
	dp1();
	dp2();
	print();

	return 0;

}

/*

4
2 1 5 3

3
1 5 5

7
1 2 3 1 3 2 1

*/
