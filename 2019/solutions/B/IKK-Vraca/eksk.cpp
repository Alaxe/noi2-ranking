#include<iostream>
using namespace std;

int main()
{
int A,B;
	int N;
	do{cin>>N;} while(N<=1 || N>200000); 
	int U[N],V[N];
	int i,j,q=1,k=1;
	for(i=0;i<N-1;i++)cin>>U[i]>>V[i];
	do{cin>>A>>B;}while(A==B || (A<1 || A>N) || (B<1 || B>N));

	int counta=0,countb=0;
	int a[N],b[N],flag1,flag2;
	a[0] = A;
	b[0] = B;
	
	int cikul=0;
	do
	{
		for(i=0;i<N;i++)
		{
		if(counta<=countb)if(A==U[i]){
		 flag1=1;
		 for(j=0;j<k;j++)if(V[i]==b[j]){flag1=0;break;}
		 if(flag1){ a[q]=A;q++;A=V[i]; counta++;  }
		 }
		else if(A==V[i]){ 
		flag1=1;
		for(j=0;j<k;j++)if(A==b[j]){flag1=0;break;}
		if(flag1){ a[q]=A;q++;A=U[i];counta++; }
		}
		
		if(countb<=counta)if(B==U[i]){
		 flag2=1;
		 for(j=0;j<q;j++)if(B==a[j]){flag2=0;break;}
		 if(flag2){b[k]=B;k++;B=V[i];countb++;}
		 }
		else if(B==V[i]){ 
		flag2=1;
		for(j=0;j<q;j++)if(B==a[j]){flag2=0;break;}
		if(flag2){b[k]=B;k++;B=U[i];countb++;}
		}
	}
	cikul++;
	}while(cikul<N);
	
	cout<<counta;
	return 0;
}
