#include<iostream>
#include<cmath>
using namespace std;
int main()
{
long long int n;
cin>>n;
char c1;
char a,b,c,d;
long long int br=0,bra=0,brb=0,brc=0,brd=0;
for(int i=0;i<n;i++)
{
    cin>>c1;
    if(c1=='a')
    {
        a='a';
        bra++;
    }
    if(c1=='b')
    {
        b='b';
        brb++;
    }
    if(c1=='c')
    {
        c='c';
        brc++;
    }
    if(c1=='d')
    {
        d='d';
        brd++;
    }
    if(a='a'&&b=='b'&&c=='c'&&d=='d')
    {
        br+=4;
        a=0,b=0,c=0,d=0;
        bra--;brb--;brc--;brd--;
    }
}
if(bra==brb&&bra==brc&&bra==brd&&brb==brc&&brb==brd&&brc==brd)
{
    br+=(bra*4);
}
cout<<br<<endl;
return 0;
}
