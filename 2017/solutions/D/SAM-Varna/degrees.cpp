#include<iostream>
#include<string>
using namespace std;
string s;
void Read()
{
    cin>>s;
}
void Solve()
{
    int c=1;
    s="1"+s;
    int st=-1;
    int n=s.size();
    int brc;
    while(n>0)
    {
        if(c%3==1) brc=4;
        else brc=3;
        if(brc*c<n)
        {
            n=n-brc*c;
            st+=brc;
        }
        else
        {
           for(int j=brc;j>=1;j--)
           {
               if(j*c<=n)
               {
                   st=st+j;
                   break;
               }
           }
           n-=brc*c;
        }
        c++;
    }
    cout<<st;
}
int main()
{
    Read();
    Solve();
    return 0;
}
