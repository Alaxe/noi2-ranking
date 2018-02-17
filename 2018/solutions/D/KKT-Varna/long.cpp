#include<bits/stdc++.h>
using namespace std;

string suma(string a,string b){
  int p=0,r,n,is=0,i=a.size(),j=b.size();
  if(i!=j){
    string c;
    int h=max(i,j)-min(i,j);
    for(;h;--h){
      c="0"+c;
      }
    if(i<j)a=c+a;
    else b=c+b;
    }
  i=max(i,j);
  for(n=i-1;n>-1;--n){
    r=a[n]+b[n]-'0'*2+is;
    a[n]=char(r%10+'0');
    if(r>9)is=1;
    else is=0;
    }
  if(is)a="1"+a;
  return a;
  }

int main(){

string a,b,b2,b3;
long long int i,n;
cin>>n>>b;
b2=b;
i=b.size();
i=n-i;
for(int j=1;j<i;++j){
    b=b+"0";
    }
i--;
for(;;){
  b3=b2;
  for(int j=1;j<i;++j){
    b3=b3+"0";
    }
  if(suma(b,b3).size()>=n)i--;
  else b=suma(b,b3);
  if(i<2)break;
  }
for(;;){
  if(b.size()==n)break;
  b=suma(b2,b);
  }
cout<<b<<endl;

return 0;
}
