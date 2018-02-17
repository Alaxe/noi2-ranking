#include<iostream>
using namespace std;
int main(){
int N,a,b,pl,ed,des,st,h,n1,n2,i;
cin>>N;
ed=pl%10;
des=pl/10%10;
st=pl/100%10;
h=pl/1000;
if(ed==h&&des==st)pl=ed+des*10+st*100+h*1000;
n1=N-1;
{
  n2=N-2;
  if(n2*n1>pl)n2=n2-1;
  n2=N-3;
    if(n2*n1>pl)n2=n2-1;
    n2=N-4;
      if(n2*n1>pl)n2=n2-1;
      n2=N-5;
        if(n2*n1>pl)n2=n2-1;
        n2=N-6;
          if(n2*n1>pl)n2=n2-1;
          n2=N-7;
            if(n2*n1>pl)n2=n2-1;
            n2=N-8;
              if(n2*n1>pl)n2=n2-1;
              n2=N-9;
}
cout<<n2<<" "<<n1<<endl;
cout<<n2*n1<<endl;
return 0;
}
