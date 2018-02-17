#include<bits/stdc++.h>
using namespace std;
long long card[101][101];
int main()
{
int n,sum=0,maxsum=0,i,j,ace;
char a,fake,color;
cin>>n;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
{
cin>>a;
cin>>fake;
if(i==0 && j==0)color=fake;
if(a>='1' && a<='9')card[i][j]=a-'0';
else if(a=='A')card[i][j]=1;
else if(a=='T')card[i][j]=10;
else if(a=='J')card[i][j]=11;
else if(a=='Q')card[i][j]=12;
else card[i][j]=13;
}

if(n==1)cout<<card[0][0]<<endl;
if(n==2){
if(card[0][0]>card[1][1])cout<<card[0][1]+card[0][0]+card[1][0]<<endl;
else cout<<card[0][1]+card[1][1]+card[1][0]<<endl;
}
if(n==3)
{
if((card[0][2]+card[1][2]+card[2][2]+card[2][1]+card[2][0])>maxsum)maxsum=card[0][2]+card[1][2]+card[2][2]+card[2][1]+card[2][0];
if((card[0][2]+card[1][2]+card[1][1]+card[1][0]+card[2][0])>maxsum)maxsum=card[0][2]+card[1][2]+card[1][1]+card[1][0]+card[2][0];
if((card[0][2]+card[1][2]+card[1][1]+card[2][1]+card[2][0])>maxsum)maxsum=card[0][2]+card[1][2]+card[1][1]+card[2][1]+card[2][0];
if((card[0][2]+card[0][1]+card[1][1]+card[1][0]+card[2][0])>maxsum)maxsum=card[0][2]+card[0][1]+card[1][1]+card[1][0]+card[2][0];
if((card[0][2]+card[0][1]+card[1][1]+card[2][1]+card[2][0])>maxsum)maxsum=card[0][2]+card[0][1]+card[1][1]+card[2][1]+card[2][0];
if((card[0][2]+card[0][1]+card[0][0]+card[2][1]+card[2][0])>maxsum)maxsum=card[0][2]+card[0][1]+card[0][0]+card[2][1]+card[2][0];
cout<<maxsum<<endl;
}
return 0;
}
/*
4
KS KS KS KS
KS AS AS KS
KS AS AS KS
KS KS KS KS

*/
