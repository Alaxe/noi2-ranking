#include<bits/stdc++.h>
using namespace std;
string longg(string a,string k)
{
    //f(a.size()==n)return a;
    int ost=0;
    int as=a.size();
    int ks=k.size();
    if(ks>as)
    {
        swap(ks,as);
        swap(a,k);
    }
    string s="";
    while(as>0)
    {
        as--;
        ks--;
        if(ks>=0)
        {
            int sum=(char(a[as]-'0')+char(k[ks]-'0'))+ost;//cout<<sum<<endl;
            s=char(sum%10+'0')+s;//cout<<'!'<<s<<endl;
            if(sum>9)ost=1;
            else ost=0;
        }
        else
        {
            if(ost==1)
            {
            int sum=char(a[as]-'0')+1;//cout<<'@'<<s<<endl;
            s=char(sum%10+'0')+s;
            if(sum>9)ost=1;
            else ost=0;
            }
            else
            {
                s=char(char(a[as]-'0')+'0')+s;//cout<<'$'<<s<<endl;
            }
        }

        //cout<<s<<endl;
    }
    if(ost==1)s='1'+s;
     return s;
}

string fa(string a,int b)
{
    int sa=a.size(),ost=0;
    int br=0,b1=b;
    string s="",sum="0";
    while(b>0)
    {
    s="";
        int k=b%10;
        b/=10;
       // cout<<k<<endl;
        for(int i=sa-1;i>=0;i--)
        {
            int v=k*(a[i]-'0')+ost;
            ost=v/10;
            s=char(v%10+'0')+s;
        }
        if(ost!=0)s=char(ost+'0')+s;
        for(int i=0;i<br;i++)
        {
            s=s+'0';
        }

        // cout<<b1<<"="<<s<<endl;
        sum=longg(sum,s);

        br++;
    }
    return sum;
}
int main(){
  // cout<<longg("10","0000");
    int n,br1=0;
cin>>n;
string s="1";
for(int i=2;i<=n;i++)
{
    s=fa(s,i);
}
//cout<<s<<endl;
for(int i=0;i<s.size();i++)
{
    br1+=char(s[i]-'0');
}
cout<<br1<<endl;



return 0;
}
