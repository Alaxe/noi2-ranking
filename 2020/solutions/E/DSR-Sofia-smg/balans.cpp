#include<iostream>
using namespace std;
int main()
{
    long long n,bra=0,brb=0,brc=0,brd=0,razlika;
    cin>>n;
    for(int i=0; i<n;i++)
    {
        char abcord;
        cin>>abcord;
        if(abcord=='a')
        {
            bra++;
        }
        if(abcord=='b')
        {
            brb++;
        }
        if(abcord=='c')
        {
            brc++;
        }
        if(abcord=='d')
        {
            brd++;
        }
    }
    if(brd==0||brc==0||brb==0||bra==0){
        cout<<0<<endl;
    }
    if(bra+brb==brc+brd)
    {
        cout<<brb+brb+brc+brd<<endl;
    }
    else if(bra+brb>brc+brd)
{
    razlika=bra+brb-brc-brd;
    cout<<brb+brb+brc+brd-razlika<<endl;
}
else if(bra+brb<brc+brd)
{
    razlika=brc+brd-bra-brb;
    cout<<brb+brb+brc+brd-razlika<<endl;
}
return 0;
}
