#include<iostream>
using namespace std;
int main()
{
    long long n,cards[100][100],sum=0,a=0,b=n-1;
    string s;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>s;
            if(s[0]=='A')cards[i][j]=1;
            if(s[0]=='2')cards[i][j]=2;
            if(s[0]=='3')cards[i][j]=3;
            if(s[0]=='4')cards[i][j]=4;
            if(s[0]=='5')cards[i][j]=5;
            if(s[0]=='6')cards[i][j]=6;
            if(s[0]=='7')cards[i][j]=7;
            if(s[0]=='8')cards[i][j]=8;
            if(s[0]=='9')cards[i][j]=9;
            if(s[0]=='T')cards[i][j]=10;
            if(s[0]=='J')cards[i][j]=11;
            if(s[0]=='Q')cards[i][j]=12;
            if(s[0]=='K')cards[i][j]=13;
        }
    }
    for(int k=0;k<6;k++)
    {
        cout<<k<<endl;
        if(a==n-1&&b==0)break;
        else
        if(a==n-1){b=b-1;sum=sum+cards[a][b-1];}
        else
        if(b==0){a=a+1;cards[a+1][b];}
        else
        if(cards[a+1][b]>=cards[a][b-1]){a=a+1;sum=sum+cards[a+1][b];}
        else {b=b-1;sum=sum+cards[a][b-1];}
    }
    cout<<sum<<endl;

    return 0;
}
