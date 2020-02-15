#include<iostream>
#include<algorithm>
using namespace std;
int n,m,g;
char og[10000],novg[10000],novm[10000];
int main(){
cin>>og;
m=og[0]-'A'+1;
g=og[0]-'A'+1;
for(n=0;  og[n]!='\0'   ;  n++)
{
     novg[n]=og[n];
     novm[n]=og[n];
     if(m>og[n]){m=og[n]-'A'+1;}
     if(g<og[n]){g=og[n]-'A'+1;}
}
for(int i=0;  i<n   ;  i++)
{
     novg[i]=novg[i]+25-g;
     novm[i]=novm[i]+1-m;
}
cout<<novm<<endl<<novg;
return 0;
}
