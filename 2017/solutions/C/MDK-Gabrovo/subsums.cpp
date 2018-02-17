#include<bits/stdc++.h>
using namespace std;
const int nmax=1000+42,MAX_NUM=1000,SZ=1e6+42+MAX_NUM,add=1e6+42+MAX_NUM;
bool can[SZ+add],can2[SZ+add];
int n,a[nmax];
int main()
{
cin>>n;
for(int i=1;i<=n;i++)
{
cin>>a[i];
int LIM=i*MAX_NUM;
for(int j=-LIM;j<=LIM;j++)//New
     if(can[j+add-a[i]]==1||j-a[i]==0){can2[j+add]=1;/*cout<<i<<" "<<j<<endl;*/}
for(int j=-LIM;j<=LIM;j++)
    can[j+add]=can2[j+add];
}
int total=0;
int LIM=n*1000;
for(int i=-LIM;i<=LIM;i++)total=total+can[i+add];
cout<<total<<endl;
return 0;
}
/*
5
1 -2 0 7 7

*/
