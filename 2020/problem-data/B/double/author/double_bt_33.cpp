#include<iostream>
#include<cstring>
using namespace std;


const int N=1000;
int a[N];
int n,w1,w2;


int rec;
int r1,r2;


void go(int i)
{
    if(r1>w1) return;
    if(r2>w2) return;

    if(i==n)
    {
     if(rec < r1+r2) {rec=r1+r2;}
     return;
    }

    go(i+1);

    r1+=a[i];go(i+1);r1-=a[i];

    r2+=a[i];go(i+1);r2-=a[i];

}


int main()
{
	cin >> n >> w1 >> w2;
	for(int i=0;i<n;i++) cin >> a[i];
	go(0);
	cout << rec << endl;
}
