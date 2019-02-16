#include <iostream>
using namespace std;
int a[100010], n;
int ll[100010],rr[100010];
int MaxL, MaxR, MaxS, Otg;

void left(){
int i,j,mm;
	ll[0]=1; MaxL=0;
	for (i=1;i<n;i++){
		mm=0;
		for(j=0; j<i; j++)
			if (a[i]>a[j]) mm=max(mm,ll[j]);
		ll[i]=mm+1;	
		MaxL=max(MaxL,ll[i]);
	}
}

void right(){
int i,j,mm;
	MaxR=MaxS=Otg=0;
	rr[n-1]=1;
	for (i=n-2;i>=0;i--){
		mm=0;
		for(j=i+1; j<n; j++)
			if (a[i]>a[j]) 
				mm=max(mm,rr[j]);
		rr[i]=mm+1;
		MaxR=max(MaxR,rr[i]);
		MaxS=max(MaxS,rr[i]+ll[i]);
	}
	MaxS--;
	Otg=max(MaxL,max(MaxR,MaxS));
	cout<<Otg<<endl;
}

int main()
{
	int i,q,k,p;
	MaxL=MaxR=MaxS=Otg=0;
	
	cin>>n;
	for(i=0; i<n; i++)
		cin>>a[i];		
	left();
	right();
	
	return 0;
}
/*
6
3 1 4 6 2 5

14
6 3 8 1 5 8 4 6 5 3 6 2 7 4

9
5 3 8 7 1 6 4 6 5

13
4 2 6 3 4 8 5 3 9 8 6 5 9

14
5 8 4 9 3 8 7 5 8 4 3 9 5 7

22
4 90 7 4 9 6 33 12 8 5 17 9 12 23 7 6 33 32 78 23 9 12  

7
6 6 6 6 5 6 6

7
11 9 6 6 5 6 6

7
4 2 5 8 4 3 9

44
4 90 7 4 9 6 33 12 8 5 11 9 12 43 7 6 33 22 78 23 9 32 4 80 7 4 9 6 33 12 8 95 17 9 1 23 7 6 33 32 78 23 19 12 
*/
