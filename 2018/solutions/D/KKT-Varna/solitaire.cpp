#include<bits/stdc++.h>
using namespace std;
int main(){

char k;
int n,h,i,j;
cin>>n;
int m[n][n];
for(i=0;i<n;++i){
  for(j=0;j<n;++j){
    cin>>k;
    if(k<='9')h=k-'0';
    else if(k=='A')h=1;
    else if(k=='T')h=10;
    else if(k=='J')h=11;
    else if(k=='Q')h=12;
    else if(k=='K')h=13;
    m[i][j]=h;
    cin>>k;
    }
  }
int a1=0,a2=0,a4=0,a3=0;
for(i=0;i<n;i++){a1+=m[0][i];}
for(i=n-1;i<-1;--i){a2+=m[0][i];}
for(i=0;i<n;i++){a3+=m[i][0];}
for(i=n-1;i<n;i++){a4+=m[i][0];}
int s1=a1+a4;
int s2=a2+a3;
if(s1>s2)cout<<s1;
else cout<<s2;
cout<<endl;

return 0;
}
/*
4
8S AD 3C AC
8C 4H QD QS
5D 9H KC 7H
TC QC AS 2D
*/
