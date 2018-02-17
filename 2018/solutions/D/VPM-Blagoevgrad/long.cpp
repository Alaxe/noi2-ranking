#include<bits/stdc++.h>
using namespace std;
int n;
string k;
string longg(string a)
{
    //f(a.size()==n)return a;
    int ost=0;
    int as=a.size();
    int ks=k.size();
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

int main(){
cin>>n>>k;
string s=k;
while(s.size()!=n)
{
  s=longg(s);
  //cout<<"s="<<s<<endl;

}
cout<<s<<endl;

return 0;
}
