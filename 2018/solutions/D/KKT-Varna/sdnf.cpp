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

string multy(string a,int b){
  int is=0,k;
  for(int i=a.size()-1;i>-1;--i){
    k=(a[i]-'0')*b+is;
    a[i]=char((k%10)+'0');
    is=k/10;
    }
  char l=is+'0';
  if(is)a=l+a;
  return a;
  }

string mult(string a,int i){
  string b,c;
  int n=0,h;

  for(;i;i/=10){
    b="";
    h=i%10;
    if(h)b=multy(a,h);
    if(n){for(int n2=n;n2;--n2)b=b+"0";}
    c=suma(c,b);
    ++n;
    }
  return c;
  }

void cif(string a){
  long long int n=0;
  for(int i=0;i<a.size();++i)n+=a[i]-'0';
  cout<<n<<endl;
  }

int main(){

string a="1";
int i,n;
cin>>n;
for(i=1;i<=n;++i)a=mult(a,i);
cif(a);

return 0;
}
