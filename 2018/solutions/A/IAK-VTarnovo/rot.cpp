#include <iostream>
#include <math.h>
using namespace std;int b,m[4],br=0,x,n,q;
int rot(int A)
{
	x=A;
		while(x!=0)
		{
			x=x/10; br++;
		}
		n=pow(10,br-1);
		q=A%n; 
		q=A/n+(q)*10; 
		br=0;return q;

}
int main()
{
	int br1=0;
	cin>>b;
	for(int i=0;i<4;i++) cin>>m[i];

	for(int i=0;i<4;i++) 
	
			{for(int j=1;j<=m[i];j++)
 				{
 						if(rot(j)-j==m[i]) {
						 cout<<j<<endl; br1++;} 
						 
						 if(br1!=0){
						 	cout<<"0"<<endl;br1=0;
						 }
 							} 
 
 }
	
}
