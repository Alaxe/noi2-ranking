#include<iostream>
using namespace std;
int b;
string del(string a)
{
    int n=a.size();
    string ans="";
    int p=0;
    for(int i=0;i<n;i++)
    {
        p=p*b+a[i]-'0';
        int d=p/(b-1);
        if(i==0 and d==0)ans="";
        else
        {
            ans=ans+char(d+'0');
        }
        if(i==n-1 and p%(b-1)!=0)return "0";
        p=p%(b-1);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>b;
    for(int str=1;str<=4;str++)
    {
        string a;
        cin>>a;int n=a.size();
        for(int j=0;j<n;j++)
        {
            if(a[j]>='A' and a[j]<='P')
                a[j]=char((a[j]-'A')+'9'+1);
        }
        if(a[0]-'0'==b-2){cout<<0<<endl;continue;}
        if(a[0]-'0'==b-1){a="0"+a;n++;}
            a[0]++;

        int i=n-1;
        while(a[i]=='0')
        {
            a[i]=((b-1)+'0');
            i--;

        }
        a[i]--;
        string ans=del(a);
        if(ans=="0")cout<<0<<endl;
        else
        {
            cout<<1;
            int as=ans.size();
            for(int q=0;q<as;q++)
            {
                if(ans[q]>='0' and ans[q]<='9')cout<<ans[q];
                else cout<<char((ans[q]-'0'-10)+'A');
            }
            cout<<endl;
        }
    }
    return 0;
}
