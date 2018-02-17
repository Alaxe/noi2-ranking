#include<bits/stdc++.h>
using namespace std;
long long n,pr,ch,c,i,j,h,t,sum,br=1,sz;
string s="1";
int main()
{
    cin>>n;
    sz=s.size();
    for (i=2;i<=n;i++)
    {
        t=i;
        br=s.size()-1;
        while (t>0)
        {
            if (t%10!=0) ch=t%10;
            else
            {
                while (t%10==0)
                {
                    s=s+'0';
                    t=t/10;
                }
                ch=t%10;
            }

            for (j=sz-1,h=br;j>=0;j--,h--)
            {
                c=(s[j]-'0')*ch+pr;
                pr=c/10;
                c=c%10;
                if (h>=0) s[j]=char(c+'0');
                else s=char(c+'0')+s;
            }
            if (pr>0) s=char(pr+'0')+s;
            pr=0;
            t=t/10;
            br--;
            sz=s.size();
        }
    }
    for (i=1;i<=s.size();i++) sum=sum+(s[i-1]-'0');

    cout<<sum<<endl;
}
/**
7 9
65 351
953 9774
8793 129294
*/
