#include <iostream>
using namespace std;

int main(){
long long pristiganeNaPac[720],vreme[720],posleden=0,buf[2],broipac,i,ii,pregledani;
cin>>broipac;
for(i=0;i<broipac;i++)
{cin>>pristiganeNaPac[i]>>vreme[i];}
for(i=broipac-1;i>=0;i--)
{ for (ii=i-1;ii>=0;ii--)
{if(pristiganeNaPac[i]<pristiganeNaPac[ii])
{buf[0]=pristiganeNaPac[i];buf[1]=vreme[i];
pristiganeNaPac[i]=pristiganeNaPac[ii];vreme[i]=vreme[ii];
pristiganeNaPac[ii]=buf[0];vreme[ii]=buf[1];}}}
posleden=pristiganeNaPac[0]+vreme[0];
for (pregledani=1;pregledani<broipac;pregledani++)
{if(pristiganeNaPac[pregledani]>posleden)
{posleden=pristiganeNaPac[pregledani]+vreme[pregledani];}
else {posleden=posleden+vreme[pregledani];}
}
cout<<posleden-pristiganeNaPac[broipac-1];
return 0;
}
