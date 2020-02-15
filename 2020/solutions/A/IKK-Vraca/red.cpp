#include <iostream>
using namespace std;
int N,M;
int K;

void var1()   // dif
{
	
}

void var2(int A[],int B[])   // equals
{
	// K-подредици на А -> U
	int U[N][K];
	
	int k1=0;
	
	// podredica A
	for(int i=0;i<N-K+1;i++)
	{
		int m=0;
	for(int j=0;j<K-1;j++)
	{
		if(A[i+j]==A[i+j+1]){
			U[k1][m]=A[i+j];
			m++;
		} else {m=0; break;}
	}
	U[k1][K-1]=A[i+K-1];
	k1++;
	if(m==0)k1--;
	else m=0;
	
} 

//	cout<<"k="<<k<<endl;
	// К-подредици на B -> V
	
	int k2=0;
	int V[M][K];
		// podredica B
for(int i=0;i<M-K+1;i++)
	{
		int m=0;
	for(int j=0;j<K-1;j++)
	{
		if(B[i+j]==B[i+j+1]){
			V[k2][m]=B[i+j];
			m++;
		} else {m=0; break;}
	}
	V[k2][K-1]=B[i+K-1];
	k2++;

	if(m==0)k2--;
	else m=0;

} 


	// Проверка дали съвпадат
	int count=0;
	for(int i=0;i<k1;i++)
	for(int j=0;j<k2;j++)
	{
		if(U[i][0] == V[j][0])count++;
	}

cout << count;



}





int main(){
int W;
cin>>W>>K;
cin>>N; int A[N];
for(int i=0;i<N;i++)cin>>A[i];
cin>>M; int B[M];
for(int i=0;i<M;i++)cin>>B[i];

if(W==1) var1();         
else if(W==2) var2(A,B);

}

