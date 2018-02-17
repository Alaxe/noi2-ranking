#include<iostream>
using namespace std;
int main(){
int chisloVhod;
cin>>chisloVhod;
for(int i=1;i=chisloVhod*2;i++)
{
int vhod[i],brZaKrai,i2,i1,i3;
i2=i+2;
i1=i+1;
i3=i+3;
vhod[i]<=i;
cin>>vhod[i];
if(vhod[i]<=vhod[i-1]){
       swap(vhod[i],vhod[i-1]);
}
if(vhod[i]<=vhod[i2] || vhod[i1]<=vhod[i3]){
       brZaKrai=brZaKrai/100000+1;
}
cout<<brZaKrai/10;
return 0;
}
}
