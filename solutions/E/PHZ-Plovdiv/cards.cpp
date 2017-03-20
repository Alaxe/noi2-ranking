#include<iostream>
using namespace std;
int main()
{
int N,a1,a2,b1,b2,br1,br2,br3,br4,x,rez1,rez2;
cin>>N;
x = N;
cin>>a2>>b2;
br1 = 1;
br2 = 1;
N = N-1;
if(N!=0){
do
{
    cin>>a1>>b1;
    if((a1>=b2)&&(b1>=a2)){a2 = a1; b2 = b1; br1++; N=N-1; if(br2<br1){br2 = br1;};};
    if((a1>=a2)&&(b1>=b2)){a2 = a1; b2 = b1; br1++; N=N-1; if(br2<br1){br2 = br1;};};
    if((a1<a2)&&(a1<b2)){br1 = 0; N=N-1;};
    if((b1<a2)&&(b1<b2)){br1 = 0; N=N-1;};
}
while(N>0);}
if(x=5)
{cout<<br2<<endl;}
if(x<5)
{rez1 = 5-x; br3 = br2+rez1+1; cout<<br3<<endl;}
if(x>5)
{rez2 = x-5; br4 = br2-rez2+1; cout<<br4<<endl;}
return 0;
}
