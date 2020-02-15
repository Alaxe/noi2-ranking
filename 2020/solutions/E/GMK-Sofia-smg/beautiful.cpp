#include<iostream>
using namespace std;
int main()
{
    long long N,br=0,c,r,s,i;
    bool l;
    cin>>N;
    for(i=1;i<=N;i++)
    {
        c=i%10;
        l=true;
        s=0;
        if(i<10)
        {
            br++;
        }
        for(r=i;r>9 && l==true;r=r+0)
        {
            r=r/10;
            if(c==r%10)
            {
                s=1;
            }
            else
            {
                l=false;
            }
        }
        if(l==true)
        {
            br=br+s;
        }
    }
    cout<<br;
}
