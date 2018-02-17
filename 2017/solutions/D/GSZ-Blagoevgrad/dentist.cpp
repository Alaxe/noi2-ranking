#include  <bits/stdc++.h>
using  namespace  std;
struct pacient
{
    int pristiga;
    int svyrshva;
    int lekyva;
};
bool cmp (pacient a, pacient b)
{
    if(a.pristiga<=b.pristiga)return 1;
    return 0;
}
int main()
{
ios_base::sync_with_stdio(false);
pacient gosho[730];
pacient pesho;
int j=0,idva;
while(  cin>>pesho.pristiga>>pesho.lekyva)
{
    pesho.svyrshva=pesho.pristiga+pesho.lekyva;
    gosho[j]=pesho;j++;
}
cin.clear();
sort(gosho,gosho+j,cmp);
pesho.pristiga=gosho[0].pristiga;
pesho.lekyva=gosho[0].lekyva;
pesho.svyrshva=gosho[0].svyrshva;
for(int i=1;i<j;i++)
{
    if(i==j-1){idva=gosho[i].pristiga;}
    if(gosho[i].pristiga<pesho.svyrshva)
    {
        gosho[i].pristiga = pesho.svyrshva;
        gosho[i].svyrshva = gosho[i].pristiga+gosho[i].lekyva;
    }
    pesho=gosho[i];
}
cout<<pesho.svyrshva-idva<<'\n';
return 0;
}
/*
0 30
720 10
715 20
714 25
*/
