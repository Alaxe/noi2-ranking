#include<iostream>
using namespace std;
int main()
{
    long long duljina,bra,brb,brc,brd,i;
    cin>>duljina;
    char redica[1000000];
    cin>>redica;
    for(long long j=duljina;j>0;j--)
    {
        bra=0;
        brb=0;
        brc=0;
        brd=0;
        for(i=0;i<j;i++)
        {

            if(redica[i]=='a')
            {
                bra++;
            }
            if(redica[i]=='b')
            {
                brb++;
            }
            if(redica[i]=='c')
            {
                brc++;
            }
            if(redica[i]=='d')
            {
                brd++;
            }
            ///cout<<bra<<" "<<brb<<" "<<brc<<" "<<brd<<"\n";

        }
        if( (bra + brb) == (brc + brd) )
            {
                cout<<i;
                return 0;
            }
    }
    cout<<0;
    return 0;
}
