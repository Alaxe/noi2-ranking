#include<iostream>
using namespace std;
string sbor(string s,string f)
 {
     int i,j,ds,df,k=0,p;
     string q="";
     ds=s.size()-1;
     df=f.size()-1;
     if(df<ds)swap(f,s);
     ds=s.size()-1;
     df=f.size()-1;

     while(ds<df)
     {
         s='0'+s;
         ds++;
     }
     //cout<<s<<endl;
     //cout<<f<<endl;
     for(i=df;i>=0;i--)
     {
         p=(s[i]-'0')+(f[i]-'0')+k;
         p=p%10;
         q=char(p+'0')+q;
         k=((s[i]-'0')+(f[i]-'0')+k)/10;
     }
     if(k>0)q=char(k+'0')+q;
     return q;
 }
 string umn1(string s,int k)
 {
     int ds,i,j=0,p;
     string q="";
     ds=s.size()-1;
     for(i=ds;i>=0;i--)
     {
         p=(s[i]-'0')*k+j;
         p%=10;
         //cout<<j<<endl;
         q=char(p+'0')+q;
         j=(((s[i]-'0')*k)+j)/10;
     }
     if(j>0)q=char(j+'0')+q;
     return q;
 }
 string umn2(string s,string f)
 {
     int i,j,ds=0,df,p,br=0;
     string q="",u="";
     ds=s.size()-1;
     df=f.size()-1;
     if(ds<df)swap(s,f);
     ds=s.size()-1;
     df=f.size()-1;
     for(i=df;i>=0;i--)
     {
         p=f[i]-'0';
         u=umn1(s,p);
         for(j=1;j<=br;j++)
         {
             u=u+'0';
         }
         //cout<<u<<endl;
         q=sbor(q,u);
         br++;
     }
     return q;
 }
int main()
{
    long long n,i,j,br=0,ds,sb=0;
    cin>>n;
    string s="",l="",q="1";
    for(i=1;i<=n+1;i++)
    {

        j=i;
        br=0;
        while(j>0)
        {
            l=char((j%10)+'0')+l;
            br++;
            j/=10;
        }
        q=umn2(q,l);
        //cout<<l<<endl;
        l.erase(0,br);
    }
    //cout<<q<<endl;
    ds=q.size()-1;
    for(i=0;i<=ds;i++)
    {
        sb+=q[i]-'0';
    }
    cout<<sb;
    return 0;
}
