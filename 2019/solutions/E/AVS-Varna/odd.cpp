#include<iostream>
using namespace std;
int main(){
long long int a,b,br=0,k=a,d;
cin>>a>>b;
while(k<=b)
{if(k!=d*d)k++;
if(k==d*d)br++;}
cout<<br<<endl;
return 0;
}
