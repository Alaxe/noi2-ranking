#include<iostream>
using namespace std;
long long ans,n,a,b,m,mm;
int main()
{
    cin>>n;
    string cards[n][n];
    long long card[n][n];
    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<=n-1;j++)
        {
            cin>>cards[i][j];
            if(cards[i][j][0]=='A')     {a=1;}
            else if(cards[i][j][0]=='T')     {a=10;}
            else if(cards[i][j][0]=='J')     {a=11;}
            else if(cards[i][j][0]=='Q')     {a=12;}
            else if(cards[i][j][0]=='K')     {a=13;}
            else       {a=cards[i][j][0]-'0';}
            if(cards[i][j][1]=='C')     {b=1;}
            if(cards[i][j][1]=='D')     {b=2;}
            if(cards[i][j][1]=='H')     {b=3;}
            if(cards[i][j][1]=='S')     {b=4;}
            card[i][j]=a*b;
            if(max(card[i][j],m)!=m)    {m=mm;   m=card[i][j];}
            //cout<<card[i][j]<<endl;
        }
        //cout<<"i-"<<i<<":"<<n-1<<endl;
    }
    cout<<m+mm-1<<endl;
    return 0;
}
