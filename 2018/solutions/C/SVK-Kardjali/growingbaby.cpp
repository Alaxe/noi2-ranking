#include <iostream>
using namespace std;
int main()
{int m,n,p,q,raz=0,k=0,br=0,f=0,j1=0;
cin>>m>>n>>p>>q;
raz = n - m;
k = raz / p;
for(int i = 0; i <= raz; i++)
{


for(int j = 0;  j <=i+1; j++)
{

f=(p*i - q*j);
if(f>=raz && f-p<raz && i>j){br=br+1+i%2;}
}
j1++;
}
cout<<br<<endl;
return 0;
}
