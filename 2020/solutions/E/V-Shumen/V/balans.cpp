#include<iostream>
#include<cmath>
using namespace std;
int main()
{
int n,bra=0,brb=0,brc=0,brd=0;
cin>>n;
char a;
for(int i=0;i<n;i++)
{
    cin>>a;
    if(a=='a')
    {
        bra++;
    }
    else
    {
        if(a=='b')
        {
            brb++;
        }
        else
        {
            if(a=='c')
            {
                brc++;
            }
            else
            {
                brd++;
            }
        }
    }
}
int minz=min(bra,min(brb,min(brc,brd)));
cout<<minz*4<<endl;
	return 0;
}
