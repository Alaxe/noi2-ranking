#include <iostream>
using namespace std;
int a[1000];
int main()
{
    a[0]=1;
    int n,i,br=0;
    long long k,x=1,bro=0;
    string s;
    cin>>n>>k;
    if(n<=18)
    {
        for(i=1;i<n;i++)
        {
            x=x*10;
        }
        if(x%k==0) cout<<x;
        else cout<<k*(x/k+1);
    }
    else
    {
        x=k;
        while(x!=0)
        {
            br++;
            x=x/10;
        }
        cout<<br<<endl;
        x=1;
        for(i=1;i<=br;i++)
        {
            x=x*10;
        }
        for(i=br;i<=n;i+=0)
        {
            while(x<k)
            {
                x=x*10;
                i++;
            }
            if(x/k==0) s+="0";
            else if(x/k==1) s+="1";
            else if(x/k==2) s+="2";
            else if(x/k==3) s+="3";
            else if(x/k==4) s+="4";
            else if(x/k==5) s+="5";
            else if(x/k==6) s+="6";
            else if(x/k==7) s+="7";
            else if(x/k==8) s+="8";
            else if(x/k==9) s+="9";
            bro++;
            x=x%k;
        }
        if(x!=0)
        {
            if(s[bro-1]=='9') {s[bro-1]='0';s[bro-2]=s[bro-2]+1;}
        }
        cout<<s<<endl;
    }
}
