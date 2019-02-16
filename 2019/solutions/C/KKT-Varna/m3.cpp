#include<bits/stdc++.h>
using namespace std;
int main(){

ios::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

int s,k,a,b,c,a1,b1,c1,d,br,brl;
cin>>s>>k>>a>>b>>c>>d;

br=k/(d*4);
brl=k%(d*4);

if(br==s || brl==0){
  if(brl==0)cout<<d<<".000 "<<d<<".000 "<<d<<".000 "<<d<<".000"<<endl;
  else {
    s=s*4;
    int lol=1000/s;
    cout<<k/(s*d)<<"."<<lol<<" ";
    cout<<k/(s*d)<<"."<<lol<<" ";
    cout<<k/(s*d)<<"."<<lol<<" ";
    cout<<k/(s*d)<<"."<<lol<<endl;
    }
  return 0;
  }

else if(br%4==0){a1=a;b1=c;c1=b;}
else if(br%4==1){a1=b;b1=a;c1=c;}
else if(br%4==2){a1=b;b1=c;c1=a;}
else {a1=c;b1=a;c1=b;}

brl*=1000;
a1*=1000;b1*=1000;c1*=1000;

int sa=0,sb=0,sc=0,sc1=0;

for(int i=0;i<brl;++i){
  if(sa<a1)++sa;
  else if(sa>=a){
    if(sb>sa)++sa;
    else if(sb<b1)++sb;
    else if(sb>=b){
      if(sb<sc)++sb;
      else if(sc<c1)++sc;
      else ++sc1;
      }
    }
  }

cout<<sa/1000;
cout<<".";
if(sa%1000==334)cout<<"333 ";
else {
  cout<<sa%1000;
  if(sa%1000<10)cout<<"00 ";
  else if(sa%1000<100)cout<<"0 ";
  else cout<<" ";
  }

cout<<sb/1000;
cout<<".";
if(sb%1000==334)cout<<"333 ";
else {
  cout<<sb%1000;
  if(sb%1000<10)cout<<"00 ";
  else if(sb%1000<100)cout<<"0 ";
  else cout<<" ";
  }

cout<<sc/1000;
cout<<".";
if(sc%1000==334)cout<<"333 ";
else {
  cout<<sc%1000;
  if(sc%1000<10)cout<<"00 ";
  else if(sc%1000<100)cout<<"0 ";
  else cout<<" ";
  }

cout<<sc1/1000;
cout<<".";
if(sc1%1000==334)cout<<"333";
else {
  cout<<sc1%1000;
  if(sc1%1000<10)cout<<"00";
  else if(sc1%1000<100)cout<<"0";
  }

cout<<endl;

return 0;
}
