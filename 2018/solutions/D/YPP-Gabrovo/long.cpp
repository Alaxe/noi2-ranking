#include<bits/stdc++.h>
using namespace std;

string a[1005];

int main()
{
    int n;
    string k;
    cin >> n >> k;

    for(int i=k.size()-1; i<n; i++)
    {
        a[i]+=k;
        for(int j=0; j<i-k.size()+1; j++) a[i]+='0';
    }

    string res=a[n-1],res1;
    int i=n-1;
    while(i>=k.size())
    {
        bool t=true;
        while(t)
        {
            res1=res;
            int p=0,j=n-1;
            while(j>=n-i && i-(n-j)>=0)
            {
                int x=(res[j]-'0')-(a[i-1][i-(n-j)]-'0')-p;
                if(x<0) { x+=10; p=1;}
                else p=0;
                res[j]=x+'0';
                j--;
            }
            while(j>=0 && p>0)
            {
                int x=(res[j]-'0')-p;
                if(x<0) { x+=10; p=1;}
                else p=0;
                res[j]=x+'0';
                j--;
            }
            if(res==res1) t=false;
            if(p>0) { res=res1; t=false;}
            if(res[0]=='0') { res=res1; t=false;}
        }
        i--;
    }

    cout << res << endl;

    return 0;
}
